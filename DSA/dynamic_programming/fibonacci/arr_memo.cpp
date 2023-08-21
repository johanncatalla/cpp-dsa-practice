#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<long long> dp;
public:
    Solution(int n) {
        dp.resize(n+1,-1);
    }
    long long solve(int n){
        if(n <= 1)
            return n;
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = solve(n-1)+solve(n-2);
        return dp[n];
    }
};

int main() {
    Solution fib(6);
    long long res = fib.solve(6);
    cout << res;
    return 0;
}