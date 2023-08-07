#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;

    std::cout << "Item 1: " << item1 << "\n"
              << "Item 2: " << item2 << std::endl;

    Sales_item res = item1 + item2;

    std::cout << "Item 1: " << item1 << "\n"
              << "Item 2: " << item2 << "\n"
              << "Res: " << res << std::endl;
    
    bool result = compareIsbn(item1, item2);

    bool result2 = item1 != item2;

    std::cout << result << "\n" << result2 << std::endl;
    
    Sales_item item3(std::cin);

    std::cout << "Item 3: " << item3 << std::endl;

    return 0;

}