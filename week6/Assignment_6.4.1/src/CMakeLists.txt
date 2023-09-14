add_library(exercise1 STATIC exercise1.cpp)
target_include_directories(exercise1 PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(exercise2 STATIC exercise2.cpp)
target_include_directories(exercise2 PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(exercise3 STATIC exercise3.cpp)
target_include_directories(exercise3 PUBLIC ${CMAKE_SOURCE_DIR}/include)
