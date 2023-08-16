#include <iostream>

class Swap{
public:
    void swap(int &num1, int &num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
};

int main() {
    int num1 = 1;
    int num2 = 2;
    Swap nums;
    nums.swap(num1, num2);
    std::cout << num1 << " " << num2;
    return 0;
}

