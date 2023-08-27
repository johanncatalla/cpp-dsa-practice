/*
Say that you are a traveler on a 2d grid. You begin in the top-left corner
and your goal is to travel to the bottom-right corner. You may only move down or right
In how many ways can you travel to the goal on a grid with dimensions m * n?

Write a function gridTraveler(m, n) that calculates this.
*/
#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, long long> memo;

const long long gridTraveler(int m, int n) {
    // concatenate m and n to string key
    const std::string key = std::to_string(m) + ',' + std::to_string(n);

    // check if key exists
    if (memo.find(key) != memo.end()) { return memo[key]; }
    if (m == 1 && n == 1) { return 1; }
    if (m == 0 || n == 0) { return 0; }

    // recurse to memo
    memo[key] = gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
    return memo[key];
}
 
int main() {
    std::cout << gridTraveler(2, 3) << std::endl;
    std::cout << gridTraveler(3, 3) << std::endl;
    std::cout << gridTraveler(3, 2) << std::endl;
    std::cout << gridTraveler(20, 20) << std::endl;
    return 0;
} 