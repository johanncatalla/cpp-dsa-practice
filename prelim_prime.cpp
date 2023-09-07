#include <iostream>
#include <vector>

std::vector<int> range(int x, int y) {
    int start, end;

    if (x < y) {
        start = x;
        end = y;
    } else {
        start = y;
        end = x;
    }

    std::vector<int> primes = {};
    for (int num = start; num <= end; num++) {
        bool isPrime = true;
        for (int div = 2; div <= num/2; div++) {
            if (num == 1) {
                primes.push_back(num);
            } else if (num % div == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime && num != 2) {
            primes.push_back(num);
        }
    }
    return primes;
}

int main() {
    int x, y;
    std::cout << "Enter number X: ";
    std::cin >> x;
    std::cout << "Enter number Y: ";
    std::cin >> y;

    std::vector<int> res = range(x, y);

    for (int i = 0; i < res.size(); i++) {
        if (i==0) {
            std::cout << "[" << res[i] << ", ";
        } else if (i != res.size()-1) {
            std::cout << res[i] << ", ";
        } else {
            std::cout << res[i] << "]";
        }
    }
    return 0;
}
