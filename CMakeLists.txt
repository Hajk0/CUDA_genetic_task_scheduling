cmake_minimum_required(VERSION 3.6)
project(PC-MAX LANGUAGES CXX)

# Add source files
add_executable(
    main main.cpp
    greedy/src/Greedy.cpp
    genetic/src/Individual.cpp
    genetic/src/Population.cpp
)

# Specify include directories
target_include_directories(
    main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/greedy/include
    ${CMAKE_CURRENT_SOURCE_DIR}/genetic/include
)