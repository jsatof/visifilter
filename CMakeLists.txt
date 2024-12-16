cmake_minimum_required(VERSION 3.22)

project(visifilter)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Wpedantic -Wextra -Werror -include cstdint -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -03 -Wall -Wpedantic -Wextra -Werror -include cstdint -fdiagnostics-color=always")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/dependencies.cmake)
include(cmake/options.cmake)

add_subdirectory(src)

if (BUILD_TESTS)
	add_subdirectory(test)
endif()
