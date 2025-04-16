cmake_minimum_required(VERSION 3.31)
project(OpenCV_Test)
add_executable(OpenCV_Test main.cpp)

find_package(OpenCV REQUIRED)

target_link_libraries(OpenCV_Test ${OpenCV_LIBS} ) 

add_custom_command(
    TARGET OpenCV_Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<TARGET_PROPERTY:OpenCV_Test,SOURCE_DIR>/img"
        "$<TARGET_PROPERTY:OpenCV_Test,BINARY_DIR>/img"
)

