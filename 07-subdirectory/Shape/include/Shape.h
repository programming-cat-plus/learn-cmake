#pragma once

#include <cmath>
using namespace std;

#define PI 3.1415926
class Shape{
public:
    virtual float area()=0;
    virtual float perimeter()=0;
    virtual ~Shape(){};
};