#include <iostream>

const int fib(int n) {
    if (n <= 2) { return 1; }
    return fib(n - 1) + fib(n - 2);  
}

int main() {
    int res = fib(500);
    std::cout << res;
    return 0;
}