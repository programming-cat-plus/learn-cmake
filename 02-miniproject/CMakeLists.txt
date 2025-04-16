cmake_minimum_required(VERSION 3.31)

#项目名称
project(ComplexProject VERSION 0.10 DESCRIPTION "Demo Project of Complex Number" LANGUAGES CXX)

#添加可执行程序 target = demo
add_executable(demo)
target_sources(demo PRIVATE main.cpp)


#添加库 target=complex
add_library(complex STATIC)
target_sources(complex PRIVATE complex.cpp complex.h)

#链接库
target_link_libraries(demo complex)


