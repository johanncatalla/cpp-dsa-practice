#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
private:
    std::string txt;
    std::unordered_map<char, int> memo;
    bool allOdd = true;
    bool allEven = true;
public:
    void checkOddEven(std::string txt) {
        for (short i = 0; i < txt.size(); i++) {
        if (memo.find(txt[i]) == memo.end()) {
            memo[txt[i]] = 1; 
        } else {
            memo[txt[i]] += 1;
        }
    }
        for (const auto &pair : memo) {
            if (pair.second % 2 == 0) {
                allOdd = false;
            } else {
                allEven = false;
            }
        }
        if (allOdd) {
            std::cout << "Wohoo";
        } else if (allEven) {
            std::cout << "Yey";
        } else {
            std::cout << "Meh";
        }
    }
};


int main() {
    std::string txt;
    std::cout << "Enter string: ";
    std::cin >> txt;

    Solution sol;
    sol.checkOddEven(txt);

    return 0;
}