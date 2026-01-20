cmake_minimum_required(VERSION 3.29)
project(CoreNumeric)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(Tests ${TEST_SOURCES})
