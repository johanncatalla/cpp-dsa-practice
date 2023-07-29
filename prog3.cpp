#include <iostream>
int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i) // -100 to zero = -5050, positive direction 100 cancels it out
        sum += i;
    std::cout << sum; // so sum = 0
    return 0;
}