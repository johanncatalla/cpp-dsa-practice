/*
Say that you are a traveler on a 2d grid. You begin in the top-left corner
and your goal is to travel to the bottom-right corner. You may only move down or right
In how many ways can you travel to the goal on a grid with dimensions m * n?

Write a function gridTraveler(m, n) that calculates this.
*/

#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
private:
    std::unordered_map<std::string, long long> memo;
public:
    const long long gridTraveller(short m, short n) {
        const std::string key = std::to_string(m) + ',' + std::to_string(n);

        if (memo.find(key) != memo.end()) return memo[key];
        if (m == 1 && n == 1) { return 1; }
        if (m == 0 || n == 0) { return 0; }

        memo[key] = gridTraveller(m - 1, n) + gridTraveller(m, n - 1);
        return memo[key];    
    }
};

int main() {
    Solution grid;
    long long res = grid.gridTraveller(30, 30);
    std::cout << res;
}

/*
Memoization:
1. Make it work (brute force)
    - Visualize the problem as a tree
    - implement the tree using recursion
    - test (may be slow)
2. Make it efficient
    - add memo object (map, vector etc.)
    - add base case to return memo values (find if key exists)
    - store memo values into the memo
*/

