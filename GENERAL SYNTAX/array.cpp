#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {};
    int num;
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        if (i % 2 == 0) {
            nums.push_back(i);
        }
    }

    for (int n : nums) {
        std::cout << n << std::endl;
    }

    return 0;
}