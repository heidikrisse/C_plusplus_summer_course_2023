add_library(tagged_union STATIC tagged_union.cpp)
target_include_directories(tagged_union PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(text_file STATIC text_file.cpp)
target_include_directories(text_file PUBLIC ${CMAKE_SOURCE_DIR}/include)
