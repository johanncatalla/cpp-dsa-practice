#include <iostream>

#include "rectangle.cpp"
#include "polygon.cpp"

int main(int argc, char *argv[]) {
    Rectangle rectangle("Square", 6, 6);
    std::cout << rectangle.Area();
    
    return 0;
}