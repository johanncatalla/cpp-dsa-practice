#include <iostream>

int main()
{
    // currval references the value we will read
    // val acts as a container for the succeeding numbers for comparison
    int currVal = 0, val = 0;
    // check if there is a stream of input
    if (std::cin >> currVal) {
        int cnt = 1; // count of the current value
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                          << cnt << " times " << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times " << std::endl;
    }
    return 0;
}