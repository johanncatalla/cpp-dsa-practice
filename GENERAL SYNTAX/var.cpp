#include <iostream>
#include "var1.cpp"

int main()
{
    extern const int i;
    std::cout << i;
    return 0;
}