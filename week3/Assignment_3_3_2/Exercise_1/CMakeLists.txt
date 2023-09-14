cmake_minimum_required(VERSION 3.20)

project(BasicMathFunctions)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR} include)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC basic_math_functions)

