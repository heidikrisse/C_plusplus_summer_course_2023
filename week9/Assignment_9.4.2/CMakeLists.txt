cmake_minimum_required(VERSION 3.20)

project(OptionalAndExpected)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

# Disable building tests for expected library
set(EXPECTED_BUILD_TESTS OFF CACHE BOOL "Enable tl::expected tests" FORCE)

add_subdirectory(${PROJECT_SOURCE_DIR}/include/expected)

# Include directories where header files are located
include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    PUBLIC exercise_1 exercise_2 expected
)
