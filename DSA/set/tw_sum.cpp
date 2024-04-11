#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                return {mp[complement], i};
            }
        }
        return{-1, -1};
    }
};

// implementation
int main() {
    Solution sol;
    std::vector<int> v = {2,3,11,15,6};
    int target = 9;

    std::vector<int> res = sol.twoSum(v, target);

    for (int num : res) {
        std::cout << num << " ";
    }

    return 0;
}