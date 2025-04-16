cmake_minimum_required(VERSION 3.31)
project("SimpleExample")
set(MyDemo_ROOT /demolib)
find_package(MyDemo CONFIG REQUIRED) 
add_executable(myapp src/main.cpp)  
target_link_libraries(myapp MyDemo::DemoLib)    

