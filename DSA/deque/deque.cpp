// Same as vector but with push_front and pop_front

#include <iostream>
#include <deque>

int main()
{
    std::deque<int> d = {1,2,3,4,5};

    d.pop_front();

    for(auto iter = d.begin(); iter != d.end(); ++iter)
        std::cout << *iter << " ";
    
    std::cout << std::endl;

    d.push_front(1);

    for(auto iter = d.begin(); iter != d.end(); ++iter)
        std::cout << *iter << " ";


    return 0;
}