#pragma once

#include "Shape.h"
class Rectangle:public Shape{
    private:
        float m_width;
        float m_height;
    public:
        Rectangle(float width, float height);
        float area() override;    
        float perimeter() override;        
    };