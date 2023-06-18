cmake_minimum_required(VERSION 3.20)

project(Modbus)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC modbus_simulator data_generator user_input random_number_generator file_handler device)
