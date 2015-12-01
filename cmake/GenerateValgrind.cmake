# - Generate a valgrind documentation for a project.
# The function GENERATE_VALGRIND is provided to create a "doc" target that
# generates a valgrind documentation (currently only as HTML report).
#
# GENERATE_VALGRIND(BIN "Binary to execute in valgrind")
#
#     BIN: The binary to execute
#
# This function can always be called, even if no valgrind was found. Then no
# target is created.
#
# Copyright (C) 2010 by Johannes Wienke <jwienke at techfak dot uni-bielefeld dot de>
#
# This file may be licensed under the terms of the
# GNU Lesser General Public License Version 3 (the ``LGPL''),
# or (at your option) any later version.
#
# Software distributed under the License is distributed
# on an ``AS IS'' basis, WITHOUT WARRANTY OF ANY KIND, either
# express or implied. See the LGPL for the specific language
# governing rights and limitations.
#
# You should have received a copy of the LGPL along with this
# program. If not, go to http://www.gnu.org/licenses/lgpl.html
# or write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
# The development of this software was supported by:
#   CoR-Lab, Research Institute for Cognition and Robotics
#     Bielefeld University

FUNCTION(GENERATE_VALGRIND)

  GET_FILENAME_COMPONENT(GENERATE_VALGRIND_MODULE_DIR ${CMAKE_CURRENT_LIST_FILE} PATH)
  FIND_PACKAGE(Valgrind)

  IF(VALGRIND_FOUND)
    # argument parsing
    cmake_parse_arguments(ARG "" "BIN" "ARGS" "" ${ARGN})
    SET(VALGRIND_REPORT_FILE ${CMAKE_BINARY_DIR}/valgrind.xml)

    ADD_CUSTOM_COMMAND(OUTPUT ${VALGRIND_REPORT_FILE}
                       DEPENDS ${ARG_BIN}
                       COMMAND ${VALGRIND_EXECUTABLE} ARGS --xml=yes --xml-file=${VALGRIND_REPORT_FILE} -- ${ARG_BIN} ${ARG_ARGS}
                       WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    ADD_CUSTOM_TARGET(valgrind DEPENDS ${VALGRIND_REPORT_FILE})

    MESSAGE(STATUS "Generated valgrind target (valgrind).")
  ENDIF()

ENDFUNCTION()
