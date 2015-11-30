cmake_minimum_required(VERSION 3.0.2)

include(CMakeParseArguments)

# GENERATE_TEST_TARGET(COVERAGE;VALGRIND;TARGET_NAME;FILES)
FUNCTION(GENERATE_TEST_TARGET)

  cmake_parse_arguments(ARG "" "COVERAGE;VALGRIND;TARGET_NAME" "FILES" "" ${ARGN})

  # Includes Catch in the project:
  include(AddCatch)
  enable_testing(true)  # Enables unit-testing.

  set(BIN_TEST ${ARG_TARGET_NAME})
  set(TEST_FILES ${ARG_FILES})

  add_executable(
    # executable name
    ${BIN_TEST}
    # source files
    ${TEST_FILES}
  )

  set_property(TARGET ${BIN_TEST} APPEND PROPERTY INCLUDE_DIRECTORIES ${CATCH_INCLUDE_DIR})
  add_dependencies(${BIN_TEST} catch)

  add_test(NAME catch-tester COMMAND ${BIN_TEST})

  if(ARG_COVERAGE)
    include(EnableCoverageReport)
    # --- coverage report ---
    ENABLE_COVERAGE_REPORT(TARGETS ${BIN_TEST} FILTER "${CATCH_INCLUDE_DIR}*" TESTS ${TEST_FILES} DEPTARGETS "")
  endif()

  if(ARG_VALGRIND)
    include(GenerateValgrind)
    # --- Valgrind --- #
    GENERATE_VALGRIND(BIN "${CMAKE_CURRENT_BINARY_DIR}/${BIN_TEST}")
  endif()

ENDFUNCTION()
