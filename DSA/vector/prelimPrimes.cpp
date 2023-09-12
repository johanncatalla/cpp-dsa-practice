#include <iostream>
#include <vector>

class Primes {
private: 
    std::vector<int> primes = {};
    int start, end;
public:
    // Constructor
    Primes(int x, int y) {
        if (x < y) {
            start = x;
            end = y;
        } else {
            start = y;
            end = x;
        }
    }
    
    std::vector<int> getPrimes() {
        for (int num = start; num <= end; num++) {
            bool isPrime = true;
            for (int div = 2; div <= num/2; div++) {
                if (num % div == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime && num > 1) primes.push_back(num);
        }
        return primes;
    }
    
    void printPrimes(std::vector<int> res) {
        std::cout << "[";
        for (int i = 0; i < res.size(); i++) {
            if (i != res.size()-1) {
                std::cout << res[i] << ", ";
            } else {
                std::cout << res[i];
            }
        }
        std::cout << "]";
    }
};

int main() {
    Primes primesRange(1,200);
    std::vector<int> res = primesRange.getPrimes();
    primesRange.printPrimes(res);
    
    return 0;
}
