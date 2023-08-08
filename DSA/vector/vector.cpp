#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3};

    unsigned int size = v.size();

    // push behind
    for (int i = 1; i <=5; ++i)
        v.push_back(i);

    // print beginning to end
    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i;
    
    
    return 0;
}