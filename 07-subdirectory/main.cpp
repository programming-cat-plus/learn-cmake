#include <iostream>
#include "config.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
int main(void) {
    std::cout<<"Hello World!"<<std::endl;
    std::cout<<"Version: "<<MYPROJECT_VERSION_MAJOR<<"."<<MYPROJECT_VERSION_MINOR<<std::endl;
    Circle circle(10);
    circle.area();
    Triangle triangle(10, 10,6);
    triangle.area();
    Rectangle rectangle(10, 10);
    rectangle.area();
    return 0;
}
