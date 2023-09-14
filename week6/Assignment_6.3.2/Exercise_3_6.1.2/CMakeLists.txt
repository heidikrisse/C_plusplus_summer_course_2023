cmake_minimum_required(VERSION 3.20)
project(TaggedUnion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} tagged_union)
