#include <iostream>

struct Point{
    int X;
    int Y;
};

int main() {
    Point point1;
    std::cout << "Enter X: ";
    std::cin >> point1.X;
    std::cout << "Enter Y: ";
    std::cin >> point1.Y;

    if (point1.X <= 0 || point1.Y <= 0) {
        std::cout << "Cannot form a quadrilateral!";
    } else {
        for (int y = 0; y < point1.Y; y++) {
            for (int x = 0; x < point1.X; x++) {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
        std::cout << "Perimeter: " << 2 * (point1.X + point1.Y) << std::endl;
        std::cout << "Area: " << point1.X * point1.Y << std::endl;
    }

}