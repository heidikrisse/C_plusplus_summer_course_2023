cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)    
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(executable_name main)

project(TicTacToe)
    
add_executable(${executable_name} main.cpp)
    
add_subdirectory(src)
    
target_include_directories(${executable_name} PUBLIC /include)
    
target_link_libraries(${executable_name} PUBLIC game_functions board ai_functions)
