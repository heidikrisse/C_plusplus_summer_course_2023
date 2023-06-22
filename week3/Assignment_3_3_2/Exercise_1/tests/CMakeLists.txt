set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_tests_cmake basic_math_unit_test.cpp)
target_link_libraries(unit_tests_cmake PUBLIC basic_math_functions)




