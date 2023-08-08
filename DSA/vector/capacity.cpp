#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1;

    for (int i = 1; i <= 5; ++i)
        v1.push_back(i);

    std::cout << v1.at(0) << std::endl;
    std::cout << v1[v1.size() - 1];
    return 0;
}