
add_library(Shape)

target_sources(
    Shape
    PRIVATE
        src/Circle.cpp
        src/Triangle.cpp
        src/Rectangle.cpp
)

target_include_directories(Shape PUBLIC include) 

install(TARGETS Shape DESTINATION lib)
install(FILES 
    include/Shape.h 
    include/Circle.h 
    include/Triangle.h 
    include/Rectangle.h DESTINATION include)




