set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tests_with_cmake string_utility_tests.cpp)

target_link_libraries(tests_with_cmake PUBLIC string_utils)


