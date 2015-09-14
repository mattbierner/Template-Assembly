"use strict";

var fs = require('fs');
var path = require('path');
var xml2js = require('xml2js');
 
var IN_FILE = 'x86.xml'
var OUT_FILE = 'instr.h'

var prefix =
`#pragma once
#include "immediate.h"
#include "instruction.h"
#include "modrm.h"
#include "register.h"
#include "string.h"
`;

var flatten = Function.prototype.apply.bind(Array.prototype.concat, []);

var getOperandTemplateArgs = function(operand) {
    switch (operand.$.type) {
    case 'imm8': return { type: 'Byte', needs: ['uint8_t'] };
    case 'imm16': return { type: 'Word', needs: ['uint16_t'] };
    case 'imm32': return { type: 'DWord', needs: ['uint32_t'] };

    case 'rel8': return { type: 'Rel8', needs: ['typename'] };

    case 'r8': return { type: 'GeneralPurposeRegister', args: ['1'], needs: ['size_t'] };
    case 'r16': return { type: 'GeneralPurposeRegister', args: ['2'], needs: ['size_t'] };
    case 'r32': return { type: 'GeneralPurposeRegister', args: ['4'], needs: ['size_t'] };

    case 'm128':
    case 'm256':
    
    case 'ymm':
    case 'xmm':
        
    }
    return null;
};

let padZero = (len, number) =>
    (new Array(Math.max(len - number.toString(16).length, 0)).join('0'))
        + number.toString(16);

var toModRM = function(data, operands) {
    var mode = parseInt(data.mode, 2);
    
    var reg = data.reg;
    if (reg === undefined && data['reg-operand-number']) {
        let index = data['reg-operand-number'];
        let value = argToName(operands[index])
        reg = `get_reg(${value}{})`
    }
    var rm = data.rm;
    if (rm === undefined && data['rm-operand-number']) {
        let index = data['rm-operand-number'];
        let value = argToName(operands[index])
        rm = `get_reg(${value}{})`
    }
    return `modrm<${mode}, ${reg}, ${rm}>`
};


var genNames = size =>
    "abcdefghijklmnopqrstuvwxyz".slice(0, size).split('');

var createNames = function(args) {
    var needs = flatten(args.map(x => x.needs));
    var names = genNames(needs.length);
    var i = 0;
    args.forEach(function(arg) {
        arg.needs = arg.needs.map(need => ({
            name: names[i++],
            type: need
        }));
    });
    return args;
};


let argToName = arg =>
    `${arg.type}<${(arg.args || []).concat(arg.needs.map(need => need.name)).join(', ')}>`;

var getEncoding = function(encoding, ops) {
    var prefix = [];
    if (encoding.Prefix) {
        let data = encoding.Prefix[0]['$']['byte'];
        prefix = `Prefix<'\\x${data}'>`;
    }
    
    var modrm = [];
    if (encoding.ModRM) {
        modrm = toModRM(encoding.ModRM[0].$, ops);
    }
    
    var opcode = [];
    if (encoding.Opcode) {
        opcode = encoding.Opcode.map(x => {
            let data = x.$['byte'];
            return `Opcode<'\\x${data}'>`
        });
    }
    
    var codeOffset = [];
    if (encoding.CodeOffset) {
        let index = encoding.CodeOffset[0].$['operand-number'];
        codeOffset = argToName(ops[index])
    }
    var immediate = [];
    if (encoding.Immediate) {
        let size = encoding.Immediate[0].$.size;
        let index = encoding.Immediate[0].$['operand-number'];
        let data = argToName(ops[index])
        immediate = `to_string<${size}, ${data}>`;
    }
    let data = [].concat(prefix, opcode, modrm, codeOffset, immediate).join(', ');
    return `Instruction<${data}>{}`
};



var processForm = function(name, form) {
    var operands = form.Operand;
    if (!operands || operands.length === 0) {
        let encoding = getEncoding(form.Encoding[0], []);
        return `constexpr auto ${name}() {
            return ${encoding};
        };`;
    };
     
    var aa = operands.map(getOperandTemplateArgs);
    if (aa.some(x => x === null))
        return '';
    
    var args = createNames(aa);
    var parameters = flatten(args.map(arg =>
        arg.needs.map(need =>
            need.type + ' ' + need.name)));
            
    var special = args.map(arg =>
        `${arg.type}<${(arg.args || []).concat(arg.needs.map(need => need.name)).join(', ')}>`);
    
    let encoding = getEncoding(form.Encoding[0], args);

    var base = `template <${parameters.join(', ')}>
        constexpr auto ${name}(${special.join(', ')}) {
            return ${encoding};
        };`;
    return base;
};

var processInstruction = function(instruction) {
    var name = instruction.$.name;//.toLowerCase();
    var forms = instruction.InstructionForm;
    return forms.map(
        processForm.bind(null, name));
};

var processInstructions = function(instructions) {
    return flatten(instructions.map(processInstruction));
};

 
var writeResult = function(instructions) {
    var contents = prefix + instructions.join('\n');
    fs.writeFile(path.join(__dirname, OUT_FILE), contents, function(err) {
        if(err)
            return console.log(err);
    }); 
};
 
var parser = new xml2js.Parser();

fs.readFile(path.join(__dirname, IN_FILE), function(err, data) {
    parser.parseString(data, function(err, result) {
        if (err) {
            console.error(err);
            return;
        }
        
        var instructions = processInstructions(result.InstructionSet.Instruction);
        writeResult(instructions);
    });
});