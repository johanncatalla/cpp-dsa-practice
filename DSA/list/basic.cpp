#include <iostream>
#include <list>
int main()
{
    std::list<int> l; 
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);

    // size
    unsigned int size = l.size();

    for(std::list<int>::iterator it = l.begin(); it !=l.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (auto const &v : l)
        std::cout << v;
    
    return 0;
}