#include <iostream>

#include "Rectangle.h"

int main(int argc, char *argv[]) {
    Rectangle rectangle("Square", 7, 6);
    std::cout << rectangle.Area();
    
    return 0;
}