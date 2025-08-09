cmake_minimum_required(VERSION 3.31)
project(MyProject LANGUAGES CXX VERSION 1.2.3)
set(CMAKE_CXX_STANDARD 20)
configure_file("config.h.in" "config.h")
add_executable(DemoApp main.cpp) 


target_include_directories(DemoApp PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ) 

add_subdirectory(Shape)  # Add subdirectory Shape to the project
target_link_libraries(DemoApp PRIVATE Shape)  # Link Shape library to DemoApp



