#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Using end() to iterate from the first to the last element
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using rend() to iterate in reverse from the last to the first element
    for (auto rit = myVector.rbegin(); rit != myVector.rend(); ++rit ) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}