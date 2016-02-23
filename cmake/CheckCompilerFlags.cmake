cmake_minimum_required(VERSION 3.0.2)

include(CheckCXXCompilerFlag)
include(CheckCCompilerFlag)
include(CMakeParseArguments)

# COMPILER_FLAGS(FLAGS;FLAGS_RELEASE;FLAGS_DEBUG)
MACRO(COMPILER_FLAGS)
	cmake_parse_arguments(ARG "" "" "FLAGS;FLAGS_RELEASE;FLAGS_DEBUG" "" ${ARGN})

	set(CMAKE_CXX_FLAGS "")
	set(CMAKE_C_FLAGS "")
	# General flags
	FOREACH(F ${ARG_FLAGS})
	  # We make a good unique variable name for the check
	  STRING(REGEX REPLACE "[-+=]" "_" F_CHECK_NAME ${F})
	  SET(F_CHECK_CXX_NAME CHECK_CXX_FLAG${F_CHECK_NAME})
	  # We do the check
	  CHECK_CXX_COMPILER_FLAG(${F} ${F_CHECK_CXX_NAME} HAS_FLAG)
	  # If the check passes, add the definition
	  IF(${F_CHECK_CXX_NAME})
			set(COMPILER_FLAGS_CXX_FLAGS "${COMPILER_FLAGS_CXX_FLAGS} ${F}")
	  ENDIF(${F_CHECK_CXX_NAME})
	ENDFOREACH(F ${ARG_FLAGS})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS_CXX_FLAGS}")

	# Release flags
	FOREACH(F ${ARG_FLAGS_RELEASE})
	  # We make a good unique variable name for the check
	  STRING(REGEX REPLACE "[-+=]" "_" F_CHECK_NAME ${F})
	  SET(F_CHECK_CXX_NAME CHECK_CXX_FLAG${F_CHECK_NAME})
	  # We do the check
	  CHECK_CXX_COMPILER_FLAG(${F} ${F_CHECK_CXX_NAME})
	  # If the check passes, add the definition
	  IF(${F_CHECK_CXX_NAME})
			set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${F}")
			set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${F}")
	  ENDIF(${F_CHECK_CXX_NAME})
	ENDFOREACH(F ${ARG_FLAGS})

	# Debug flags
	FOREACH(F ${ARG_FLAGS_DEBUG})
		# We make a good unique variable name for the check
	  STRING(REGEX REPLACE "[-+=]" "_" F_CHECK_NAME ${F})
	  SET(F_CHECK_CXX_NAME CHECK_CXX_FLAG${F_CHECK_NAME})
	  # We do the check
	  CHECK_CXX_COMPILER_FLAG(${F} ${F_CHECK_CXX_NAME})
	  # If the check passes, add the definition
	  IF(${F_CHECK_CXX_NAME})
			set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${F}")
			set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${F}")
	  ENDIF(${F_CHECK_CXX_NAME})
	ENDFOREACH(F ${ARG_FLAGS})
ENDMACRO()
