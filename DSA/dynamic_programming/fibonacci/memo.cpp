#include <iostream>
#include <vector>
#include <unordered_map>

// Vector is more efficient
class FibonacciVector{
private:
    std::vector<long long> memo;
public:
    // constructor
    FibonacciVector(short n) {
        memo.resize(n + 1, -1);
    }
    
    const long long fib(short n) {
        if (n <= 1) { return n; }
        if (memo[n] != -1) { return memo[n]; }        

        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }
};

class FibonacciMap{
private:
    std::unordered_map<short, long long> memo;
public:
    long long fib(short n) {
        if (n <= 1) { return n; }
        if (memo.find(n) != memo.end()) { return memo[n]; }
        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }
};

int main() {
    // vector implementation
    short num = 50;
    // resize vector
    FibonacciVector calculator(num); 
  
    long long res = calculator.fib(num);
    std::cout << "Vector: " << res << std::endl; 

    // map implementation
    FibonacciMap calculator1;
    long long result = calculator1.fib(num);
    std::cout << "Map: " << res;

    return 0;
}