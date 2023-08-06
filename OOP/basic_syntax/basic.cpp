#include <iostream>

// Parent Class
class Shape {
public:
    void setWidth(int w) {
        width = w;
    }
    void setheight(int h) {
        height = h;
    }
protected:
    int width;
    int height;
};

// Child Class
class Rectangle: public Shape {
public:
    int getArea() {
        return (width * height);
    }
};

int main(void) {
    Rectangle Rect;

    Rect.setWidth(10);
    Rect.setheight(5);

    std::cout << "Total Area: " << Rect.getArea() << std::endl;
    
    return 0;
}