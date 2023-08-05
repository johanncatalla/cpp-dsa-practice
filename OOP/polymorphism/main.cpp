#include <iostream>

#include "shape.h"

int main()
{
    Rectangle rectangle(2.0, 5.0);
    Circle circle(1.0);
    
    // Point to the rectangle
    Shape *shape = &circle;
    double area = shape->Area();
    std::cout << area << std::endl;
    return 0;
}