set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(grid_tests_results grid_tests.cpp)

target_link_libraries(grid_tests_results PUBLIC grid)

include_directories(../include)


