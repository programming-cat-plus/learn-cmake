#include "complex.h"
#include <iostream>

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c = a + b;
    std::cout << "a + b = "<<(a+b)<<std::endl;
    std::cout << "a - b = "<<(a-b)<<std::endl;
    std::cout << "a * b = "<<(a*b)<<std::endl;
    std::cout << "a / b = "<<(a/b)<<std::endl;
    return 0;
}


