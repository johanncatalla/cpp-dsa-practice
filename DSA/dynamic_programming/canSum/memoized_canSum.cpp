/*
Write a function canSum(targetSum, numbers) that takes in a targetSum and
an array of numbers as arguments.
The function should return a boolean indicating wheter or not it is possible to 
generate the target sum using numbers from the array.
* May use an element of the array as many times as needed.
* May assume all input numbers are nonnegative
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, bool> memo;
public:
    bool canSum(int targetSum, std::vector<int> numbers) {
        if (memo.find(targetSum) != memo.end()) { return memo[targetSum]; }
        if (targetSum == 0) { return true; }
        if (targetSum < 0) { return false; }    

        for (const auto &num : numbers) {
            const int remainder = targetSum - num;
            if (canSum(remainder, numbers) == true) {
                memo[targetSum] = true;
                return true;
            }
        }
        memo[targetSum] = false; 
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {7, 14};
    bool res = sol.canSum(714, nums);

    std::cout << res;

    return 0;
}
