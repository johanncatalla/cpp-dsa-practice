#include <iostream>
#include <map>

int main()
{
    std::map<int, int> m;

    m[1] = 3;
    m[1] = 4;
    m[1] = 5;
    m[3] = 6;
    m[2] = 6;
    m[4] = 7;

    int val = m.at(1);
    unsigned int count = m.count(1);

    // will print 1 because map keys are unique
    std::cout << count << std::endl;

    // Ordered maps are sorted by key
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        // can use iter->first or (*iter).first
        std::cout << iter->first << ": " << (*iter).second << std::endl; 
    }

    
    bool exists = (m.find(3) != m.end());
    if (exists)
        std::cout << "Value is in map";

    return 0;   
}