#include "Rectangle.h"

Rectangle::Rectangle(float width, float height)
{
    m_width = width;
    m_height = height;
}

float Rectangle::area()
{
    return m_width * m_height;
}

float Rectangle::perimeter()
{
    return 2 * (m_width + m_height);
}


