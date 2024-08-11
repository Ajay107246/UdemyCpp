cmake_minimum_required(VERSION 3.12)

project(udemycpp)

# Add source files
add_executable(udemycpp main.cpp """classesObjects.cpp""")

set_property(TARGET udemycpp PROPERTY CXX_STANDARD 17)

add_custom_command(
    TARGET udemycpp
    COMMAND udemycpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running udemycpp after build"
)