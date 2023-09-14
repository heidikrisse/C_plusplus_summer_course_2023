cmake_minimum_required(VERSION 3.20)

project(Animal)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Include directories where header files are located
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME}
    PUBLIC animal exercise1
)
