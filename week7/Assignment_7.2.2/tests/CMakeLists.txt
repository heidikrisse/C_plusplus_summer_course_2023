set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testitulosten_nimi unit_tests.cpp)

target_link_libraries(testitulosten_nimi PUBLIC file_name1)
