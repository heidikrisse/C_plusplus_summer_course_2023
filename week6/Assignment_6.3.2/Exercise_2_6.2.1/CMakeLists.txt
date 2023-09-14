cmake_minimum_required(VERSION 3.20)

project(PositiveIntegerOperations)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME}
    PUBLIC positive_integer
    PUBLIC counted_instance
)
