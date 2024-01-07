cmake_minimum_required(VERSION 3.28.0)

project(numerical_methods "CXX")

file(GLOB_RECURSE sources
    "${CMAKE_CURRENT_SOURCE_DIR}/algorithms/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

add_executable(${PROJECT_NAME} ${sources})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/algorithms/include/*h"
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# How to compile
# Open the Visual Studio 2022 Developer Command Prompt v17.7.2
# run in build folder the command cmake .. && cmake --build . --config Release
