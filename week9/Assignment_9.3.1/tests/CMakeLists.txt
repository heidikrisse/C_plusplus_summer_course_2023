set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_tests_results unit_tests.cpp)

target_link_libraries(unit_tests_results PUBLIC string_adapter unicode_iterator)
