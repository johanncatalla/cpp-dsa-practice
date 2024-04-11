#include <iostream>
#include <unordered_map>

std::unordered_map<short, long long> memo;
const long long fib(int n) {
    
    if (memo.find(n) != memo.end()) { return memo[n]; } 
    if (n <= 2) { return 1; }
    memo[n] = fib(n - 1) + fib(n - 2);

    // print
    //for (auto iter = memo.begin(); iter != memo.end(); iter++) {
      //  std::cout << iter->first << ": " << iter->second << "\n";
    //}

    return memo[n];
} 
/*
const long long calculate(int n) {
    std::unordered_map<short, long long> memo;
    return fib(n, memo);
}
*/
int main() {
    long long res = fib(600);
    std::cout << res;

    return 0;
}