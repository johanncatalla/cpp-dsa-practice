#include <iostream>
#include <list>

/*
Use for:
    Insertion into the middle/beginning of list
    Efficient sorting (pointer swap vs copying)
Do not use for:
    Direct Access
*/

int main()
{
    std::list<int> l; 
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);

    // insert at index
    // using std::next
    auto iter = std::next(l.begin(), 1);
    l.insert(iter, 6);

    // using advace(iterator, step)
    auto iter1 = l.begin();
    advance(iter1, 1);
    l.insert(iter1, 7);

    for(std::list<int>::iterator it = l.begin(); it !=l.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (auto const &v : l)
        std::cout << v;
    
    l.pop_front();
    l.pop_back();
    l.erase(l.begin());


    return 0;
}