#include "Triangle.h"

Triangle::Triangle(float a, float b, float c)
{
    m_a = a;
    m_b = b;
    m_c = c;
}
float Triangle::area()
{
    float p = (m_a + m_b + m_c) / 2;
    return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}
float Triangle::perimeter()
{
    return m_a + m_b + m_c;
}
