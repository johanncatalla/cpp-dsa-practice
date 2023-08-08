#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, int> m;

    m["B100"] = 100;
    m["A101"] = 101;
    m["DP102"] = 102;
    m["EP103"] = 103;
    m.insert({"CP104", 104});

    // Unordered map is not sorted
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        std::cout << iter->first << ": " << iter->second << std::endl;
    }

    return 0;
}