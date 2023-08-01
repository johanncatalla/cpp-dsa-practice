#include <iostream>
void print()
{
    std::cout << "Hello World" << std::endl;
}
int main()
{
    std::cout << "Enter values" << std::endl;
    int negative = 0, value; 
    while (std::cin >> value)
        if (value < 0) {
            ++negative;
        }
    std::cout << "Number of negative numbers: " << negative << std::endl;
    print();
    return 0;
}
