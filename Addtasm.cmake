cmake_minimum_required(VERSION 2.8.8)
include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
    tasm
    PREFIX ${CMAKE_BINARY_DIR}/tasm
    GIT_REPOSITORY https://github.com/mattbierner/Template-Assembly.git
    TIMEOUT 10
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
   )


# Expose required variable (TASM_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(tasm source_dir)
set(includeDir ${source_dir}/include ${source_dir}/instructions-set)
set(TASM_INCLUDE_DIR ${includeDir} CACHE INTERNAL "Path to include folder for tasm")
