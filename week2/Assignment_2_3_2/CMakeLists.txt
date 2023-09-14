cmake_minimum_required(VERSION 3.20)

project(SensorDataProgram)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC 
  user_interface 
  sensor_functions 
  print_functions)
