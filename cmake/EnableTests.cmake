cmake_minimum_required(VERSION 3.0.0)

# Add test target
# --- enable unit tests if desired ---
if(BUILD_TESTS)
  # Includes Catch in the project:
  include(AddCatch)
  enable_testing(true)  # Enables unit-testing.

  add_executable(
    # executable name
    ${BIN_TEST}
    # source files
    ${TEST_FILES}
  )

  set_property(TARGET ${BIN_TEST} APPEND PROPERTY INCLUDE_DIRECTORIES ${CATCH_INCLUDE_DIR})

  add_dependencies(${BIN_TEST} catch)
  target_link_libraries(${BIN_TEST} ${LIB_NAME})

  set(TEST_REPORT_FILE "testresults.xml")
  set(TEST_REPORT_TARGET "testreport")
  add_test(NAME catch-tester COMMAND ${BIN_TEST})

  list(APPEND testerArgs "--catchoption=-r junit --out ${TEST_REPORT_FILE}")

  # Execute ${CMAKE_CURRENT_BINARY_DIR}/${TEST_EXEC} binary to execute tests
  add_custom_command(OUTPUT ${TEST_REPORT_FILE}
    DEPENDS ${BIN_TEST}
    COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${BIN_TEST}" ARGS ${testerArgs}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  add_custom_target(${TEST_REPORT_TARGET} DEPENDS ${TEST_REPORT_FILE})

  if(BUILD_TESTS_COVERAGE)
    include(EnableCoverageReport)
    # --- coverage report ---
    ENABLE_COVERAGE_REPORT(TARGETS ${BIN_TEST} FILTER "${LIB_DIR}*" TESTS ${TEST_FILES} DEPTARGETS ${TEST_REPORT_TARGET})
  endif()

  if(VALGRIND_CHECK)
    include(GenerateValgrind)
    # --- Valgrind --- #
    if (DEFINED ENV{COMMANDER_CONFIG_FILE})
      GENERATE_VALGRIND(BIN "${CMAKE_CURRENT_BINARY_DIR}/${BIN_TEST}")
    else()
      GENERATE_VALGRIND(BIN "${CMAKE_CURRENT_BINARY_DIR}/${BIN_TEST}")
    endif()
  endif()

endif()
