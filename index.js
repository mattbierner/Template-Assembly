"use strict";

const fs = require('fs');
const path = require('path');
const xml2js = require('xml2js');
 
const IN_FILE = 'x86_64.xml'
const OUT_FILE = 'template assembly/instr.h'

const prefix =
`#pragma once
#include "encoding.h"
#include "immediate.h"
#include "instruction.h"
#include "memory.h"
#include "register.h"
#include "string.h"
`;

const flatten = Function.prototype.apply.bind(Array.prototype.concat, []);

const getOperandTemplateArgs = operand => {
    const type = operand.$.type;

    const r = type.match(/^r(\d+)$/)
    if (r) {
        if ([8, 16, 32, 64].indexOf(+r[1]) >= 0)
            return [{
                type: 'GeneralPurposeRegister',
                args: [r[1] / 8],
                needs: ['size_t']
            }];
        else
            return null;
    }

    const m = type.match(/^m(\d+)$/)
    if (m) {
        if ([8, 16, 32, 64].indexOf(+m[1]) >= 0)
            return [{
                type: 'Memory',
                args: [m[1] / 8],
                needs: ['typename', 'typename', 'size_t', 'Displacement']
            }];
        else
            return null;
    }

    switch (type) {
    case 'imm8': return [{ type: 'byte', needs: ['int8_t'] }];
    case 'imm16': return [{ type: 'word', needs: ['int16_t'] }];
    case 'imm32': return [{ type: 'dword', needs: ['int32_t'] }];
    case 'imm64': return [{ type: 'qword', needs: ['int64_t'] }];

    case 'rel8': return [{ type: 'Rel8', needs: ['typename'] }];
    
    case 'ymm':
    case 'xmm':
        
    }
    return null;
};

const toModRM = (data, operands) => {
    const reg = data.reg === undefined ? -1 : data.reg;
    const names = operands.map(argToName).join(', ');
    return `typename modrm<${reg}, ${names}>::type`;
};

const toRex = (data, operands) => {
    const wrxb = ['W', 'R', 'B', 'X'].map(key => {
        let index = data[`${key}-operand-number`];
        if (index !== undefined) {
            let value = argToName(operands[index]);
            return `get_rex_r(${value}{})`;
        }
        return parseInt(data[key]) || 0;
    });
    return `make_rex<${wrxb.join(',')}>`
};


const genNames = size =>
    "abcdefghijklmnopqrstuvwxyz".slice(0, size).split('');

const createNames = args => {
    const needs = flatten(args.map(x => x.needs));
    const names = genNames(needs.length);
    let i = 0;
    args.forEach((arg) => {
        arg.needs = arg.needs.map(need => ({
            name: names[i++],
            type: need
        }));
    });
    return args;
};


let argToName = arg =>
    `${arg.type}<${(arg.args || []).concat(arg.needs.map(need => need.name)).join(', ')}>`;

const getEncoding = function(encoding, ops) {
    let prefix = [];
    if (encoding.Prefix) {
        let data = encoding.Prefix[0]['$']['byte'];
        prefix = `Prefix<'\\x${data}'>`;
    }
    
    let modrm = [];
    if (encoding.ModRM) {
        modrm = toModRM(encoding.ModRM[0].$, ops);
    }
    
    let rex = [];
    if (encoding.REX) {
        rex = toRex(encoding.REX[0].$, ops);
    }
    
    let opcode = [];
    if (encoding.Opcode) {
        opcode = encoding.Opcode.map(x => {
            let b = x.$['byte'];
            if (x.$['addend-operand-number']) {
                let reg = argToName(ops[x.$['addend-operand-number']]);
                return `typename IntToBytes<1, 0x${b} + ${reg}::index>::type`
            } else {
                return `Opcode<'\\x${b}'>`;
            }
        });
    }
    
    let codeOffset = [];
    if (encoding.CodeOffset) {
        let index = encoding.CodeOffset[0].$['operand-number'];
        codeOffset = argToName(ops[index])
    }
    let immediate = [];
    if (encoding.Immediate) {
        let size = encoding.Immediate[0].$.size;
        let index = encoding.Immediate[0].$['operand-number'];
        let data = argToName(ops[index])
        immediate = `to_string<${size}, ${data}>`;
    }
    let data = [].concat(prefix, rex, opcode, modrm, codeOffset, immediate).join(', ');
    return `Instruction<${data}>{}`
};



const processForm = function(name, form) {
    if (form.ImplicitOperand)
        return [];

    let operands = form.Operand;
    if (!operands || operands.length === 0) {
        let encoding = getEncoding(form.Encoding[0], []);
        return `constexpr auto ${name}() {
    return ${encoding};
};`;
    };
     
    let aa = operands.map(getOperandTemplateArgs);
    if (aa.some(x => x === null)) // check for unmapped args
        return [];
    aa = flatten(aa);
    
    const args = createNames(aa);
    const parameters = flatten(args.map(arg =>
        arg.needs.map(need =>
            need.type + ' ' + need.name)));
            
    const special = args.map(arg =>
        `${arg.type}<${(arg.args || []).concat(arg.needs.map(need => need.name)).join(', ')}>`);
    
    let encoding = getEncoding(form.Encoding[0], args);

    return `template <${parameters.join(', ')}>
constexpr auto ${name}(${special.join(', ')}) {
    return ${encoding};
};`;
};

const processInstruction = instruction => {
    const name = instruction.$.name;
    const forms = instruction.InstructionForm;
    return flatten(forms.map(
        processForm.bind(null, name)));
};

const processInstructions = instructions =>
    flatten(instructions.map(processInstruction));


const writeResult = instructions => {
    const contents = prefix + instructions.join('\n');
    fs.writeFile(path.join(__dirname, OUT_FILE), contents, err => {
        if(err)
            return console.log(err);
    }); 
};
 
 

const parser = new xml2js.Parser();

fs.readFile(path.join(__dirname, IN_FILE), (err, data) => {
    parser.parseString(data, function(err, result) {
        if (err) {
            console.error(err);
            return;
        }
        
        const instructions = processInstructions(result.InstructionSet.Instruction);
        writeResult(instructions);
    });
});