add_library(unicode_iterator STATIC unicode_iterator.cpp)

add_library(string_adapter STATIC string_adapter.cpp)

target_link_libraries(string_adapter PUBLIC unicode_iterator)
