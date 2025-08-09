#include "Circle.h"

Circle::Circle(float r)
{
    m_r = r;
}

float Circle::area()
{
    return PI * m_r * m_r;
}

float Circle::perimeter()
{
    return 2 * PI * m_r;
};
