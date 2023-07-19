add_library(positive_integer STATIC positive_integer.cpp)
target_include_directories(positive_integer PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(counted_instance STATIC counted_instance.cpp)
target_include_directories(counted_instance PUBLIC ${CMAKE_SOURCE_DIR}/include)
