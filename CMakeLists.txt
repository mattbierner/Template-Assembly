cmake_minimum_required(VERSION 3.0.2)

set(PROJECT_NAME TemplateAssembly)
project(${PROJECT_NAME})

# Build type
if(NOT CMAKE_BUILD_TYPE)
        if(NOT BUILD_TYPE)
                set(CMAKE_BUILD_TYPE Debug)
        else()
                set(CMAKE_BUILD_TYPE ${BUILD_TYPE})
        endif()
endif()

#Cmake Properties
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")


set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/tests")

set(BIN_TEST "tester")

message(STATUS "Building ${BUILD_TYPE} ${PROJECT_NAME}\n---------------------------")

include(CheckCompilerFlags)
include(CMakeDependentOption)
include(EnableTests)

OPTION(BUILD_TESTS "Decide if the test suite shall be built." ON)
CMAKE_DEPENDENT_OPTION(BUILD_TESTS_COVERAGE "Decide if a coverage report should be generated." OFF "BUILD_TESTS" OFF)
CMAKE_DEPENDENT_OPTION(VALGRIND_CHECK "Decide if valgrind should be executed with the test binary to check for memory leaks." OFF "BUILD_TESTS" OFF)

# C++ compiler flags
if(CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_GNUCXX OR MINGW)
  message(STATUS "Setting GCC flags\n--------------------")
else()
  message(STATUS "Setting Clang/LLVM flags\n---------------------------")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

COMPILER_FLAGS(FLAGS "-std=c++14"
                     "-Wall" "-Wextra"
                     "-pedantic"
                     "-Wcast-align" "-Wcast-qual" "-Wconversion"
                     "-Wdisabled-optimization"
                     "-Wdocumentation"
                     "-Wformat=2"
                     "-Wformat-nonliteral" "-Wformat-security"
                     "-Wformat-y2k"
                     "-Wimplicit" "-Wimport" "-Winit-self" "-Winline"
                     "-Wmissing-field-initializers" "-Wmissing-format-attribute"
                     "-Wmissing-include-dirs" "-Wmissing-noreturn"
                     "-Wpacked" "-Wpointer-arith"
                     "-Wredundant-decls"
                     "-Wstack-protector"
                     "-Wstrict-aliasing=2" "-Wswitch-default"
                     "-Wswitch-enum"
                     "-Wunreachable-code" "-Wunused"
                     "-Wunused-parameter"
                     "-Wvariadic-macros"
                     "-Wno-builtin-macro-redefined"
                     "-Wwrite-strings"
                     "-Wno-unknown-pragmas"
                     "-Wno-suggest-attribute=noreturn"
                     "-fsanitize=address"
                     "-pipe"
               FLAGS_RELEASE "-march=native" "-Wno-inline"
)

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

include_directories("${INCLUDE_DIR}")

file(GLOB TEST_FILES "${TEST_DIR}/*.cpp")

# Add test target
# --- enable unit tests if desired ---
if(BUILD_TESTS)
  GENERATE_TEST_TARGET(COVERAGE ${BUILD_TESTS_COVERAGE} VALGRIND ${VALGRIND_CHECK}
                       TARGET_NAME ${BIN_TEST} FILES ${TEST_FILES})
endif()
