#include <iostream>
#include <set>

/*
Use for:
Removing duplicates
Oredered dynamic storage

Do not use for:
Simple storage
Direct access by index

Note:
Sets are often implemented with binary search trees
*/

int main() {
    std::set<int> s;

    // General operations

    s.insert(1);
    s.insert(2);

    unsigned int size = s.size();

    for(auto iter = s.begin(); iter != s.end(); iter++) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    s.erase(2);

    // s.clear() 

    bool exists = (s.find(1) != s.end());

    std::cout << exists << std::endl;
    return 0;
}