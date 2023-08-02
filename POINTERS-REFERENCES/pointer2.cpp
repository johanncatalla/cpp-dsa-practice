#include <iostream>
int main()
{
    int val = 0;
    int *pnt = &val;
    
    if (pnt)
        std::cout << "address" << std::endl;
    if (*pnt)
        std::cout << "int" << std::endl;
    return 0;
}