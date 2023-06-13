cmake_minimum_required(VERSION 3.22)

project(restaurant_order_system)
add_executable(${PROJECT_NAME} main.cpp userInterface.cpp menu.cpp order.cpp food.cpp)

