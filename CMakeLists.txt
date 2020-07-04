cmake_minimum_required(VERSION 3.4)

project(
    mTrain
    LANGUAGES C CXX
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# TODO: don't leave these here
add_definitions(-Wall)
set(CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_STANDARD_REQUIRED  ON )

set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
    -T '${CMAKE_SOURCE_DIR}/BSP/flash.ld'")

##set(FLASH_COPY_SCRIPT python3 ${PROJECT_SOURCE_DIR}/util/flash.py)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/bin" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib" )

add_subdirectory(external/mjackets-api)
add_subdirectory(BSP)

set( ARCH STM32F7 INTERNAL )

if( IS_DIRECTORY  "${CMAKE_CURRENT_LIST_DIR}/tests" )
    add_subdirectory(tests/c)
    add_subdirectory(tests/cpp)
endif()
