/*
Write a function howSum(targetSum, numbers) that takes in a targetSum and 
an array of numbers as arguments.
The function should return an array containing any combination of the elements
that add up to exactly the targetSum. If there is no combination that adds up
to the targetSum, then return null.
If there are multilpe combinations possible, you may return any single one.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> howSum(int targetSum, std::vector<int> numbers) {
        if (targetSum == 0) { return {}; }
        if (targetSum < 0) { return {-1}; }

        for (const auto &num : numbers) {
            const int remainder = targetSum - num;
            std::vector<int> remainderResult = howSum(remainder, numbers);
            if (remainderResult != std::vector<int>{-1}) {
                remainderResult.push_back(num);
                return remainderResult;
            }
        }
        return {-1};
    }
};

int main() {
    Solution sol;
    std::vector<int> res = sol.howSum(300, {7, 14});
    for (const auto &v : res) {
        if (v != -1) {
            std::cout << v << " ";
        } else {
            std::cout << "null" << std::endl;
        }
    }
    return 0;
}