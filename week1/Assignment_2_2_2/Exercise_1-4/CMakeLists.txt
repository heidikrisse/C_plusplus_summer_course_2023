cmake_minimum_required(VERSION 3.22)

project(Calculator)

add_subdirectory(src external/include)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC includes external/include)

target_link_libraries(${PROJECT_NAME} PUBLIC argument_parser operation_executor calculator_utils)

