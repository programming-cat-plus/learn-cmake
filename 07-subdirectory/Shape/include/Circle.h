#include "Shape.h"
class Circle : public Shape
{
private:
    float m_r;

public:
    Circle(float r);
    float area() override;
    float perimeter() override;
};