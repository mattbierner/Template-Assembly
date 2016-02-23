# - Try to find the VALGRIND utility
# Will define:
#
# VALGRIND_EXECUTABLE - VALGRIND executable
# VALGRIND_VERSION - version of VALGRIND
#
# Possible hints:
# VALGRIND_ROOT - root directory of valgrind installation
#
# Copyright (C) 2011 by Johannes Wienke <jwienke at techfak dot uni-bielefeld dot de>
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

INCLUDE(FindPackageHandleStandardArgs)

# find server executable
FIND_PROGRAM(VALGRIND_EXECUTABLE valgrind
             HINTS ${VALGRIND_ROOT}/bin
                   ${VALGRIND_ROOT})

# get the version
SET(VALGRIND_VERSION "")
IF(VALGRIND_EXECUTABLE)
  EXECUTE_PROCESS(COMMAND ${VALGRIND_EXECUTABLE} --version OUTPUT_VARIABLE VALGRIND_VERSION_OUT)
  STRING(REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" VALGRIND_VERSION "${VALGRIND_VERSION_OUT}")
ENDIF()

FIND_PACKAGE_HANDLE_STANDARD_ARGS(VALGRIND DEFAULT_MSG VALGRIND_EXECUTABLE VALGRIND_VERSION)

# only visible in advanced view
MARK_AS_ADVANCED(VALGRIND_EXECUTABLE VALGRIND_VERSION)
