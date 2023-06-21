set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tests_with_cmake pascal_triangle_unit_tests.cpp)

target_link_libraries(tests_with_cmake PUBLIC pascal_triangle)


