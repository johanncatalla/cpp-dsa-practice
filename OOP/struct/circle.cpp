#include <iostream>
#include <math.h>
// Use M_PI for PI

struct Circle {
    float radius;
};

int main(void) {
    Circle circle1;
    float circumference, area;

    std::cout << "Enter radius: ";
    std::cin >> circle1.radius;

    circumference = 2 * M_PI * circle1.radius;
    area = M_PI * (circle1.radius * circle1.radius);

    printf("Circumference: %.2f \nArea: %.2f", circumference, area);

    return 0;
}