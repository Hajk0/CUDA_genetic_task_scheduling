cmake_minimum_required(VERSION 3.6)
project(PC-MAX LANGUAGES CXX CUDA)

# Add source files
add_executable(
    main main.cpp
    greedy/src/Greedy.cpp
    genetic/src/Individual.cpp
    genetic/src/Population.cpp
)

set_target_properties(main PROPERTIES 
    CUDA_SEPARABLE_COMPILATION ON
    CUDA_STANDARD 11
)

# Specify include directories
target_include_directories(
    main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/greedy/include
    ${CMAKE_CURRENT_SOURCE_DIR}/genetic/include
)

# To run project:
# cd build_cuda // in the root directory (PC-Max)
# cmake .. -G "Visual Studio 17 2022" -DCMAKE_C_COMPILER="C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.37.32822/bin/Hostx64/x64/cl.exe" -DCMAKE_CXX_COMPILER="C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.37.32822/bin/Hostx64/x64/cl.exe" // in the build_cuda directory
# msbuild PC-MAX.sln // in the build_cuda directory
# cd .. : go back to the root directory (PC-Max)
# .\build_cuda\Debug\main.exe