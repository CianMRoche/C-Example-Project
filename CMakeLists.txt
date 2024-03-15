cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(FindRoot VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add the subdirectory with the root finding methods
add_subdirectory(root_finding)

# add the executable
add_executable(FindRoot find_root.cxx)

# add the function input as a library
add_library(FunctionInput function_input.cxx)

# Use target_link_libraries to link the library to our executable
target_link_libraries(FindRoot PUBLIC RootFinding FunctionInput)

target_include_directories(FindRoot PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${CONDA_PREFIX}/include"
                           "${PROJECT_SOURCE_DIR}/root_finding"
)