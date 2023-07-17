add_library(order STATIC order.cpp)

target_include_directories(order PUBLIC ${CMAKE_SOURCE_DIR}/include)
