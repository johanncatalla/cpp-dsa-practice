#include <iostream>

int main()
{
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;

    int **&r = ppi; // references ppi
    // lines 12 and 15 are for logic purposes only and may be impractical in creating actual pointers
    // we dereferenced ppi once which returns pi before being referenced by r2
    int *&r2 = *ppi; // references pi; has the same value as int *&r2 = pi
 
    // we dereferenced ppi twice which returns pi before being referenced by r3
    int &r3 = **ppi;  // references ival; has the same value as int &r3 = ival
    
    std::cout << "r value: " << r << std::endl;
    std::cout << "r2 value: " << r2 << std::endl;
    std::cout << "r3 value: " << r3 << std::endl;
    std::cout << "r2 address: " << &r2 << std::endl;
    std::cout << ppi << std::endl; // pi address
    std::cout << *ppi << std::endl; // ival address
    std::cout << **ppi << std::endl; // ival value
    std::cout << "pi address: " << &pi << std::endl;
    std::cout << "ppi address: " << &ppi << std::endl;
    std::cout << "ival address: " << &ival << std::endl;
    std::cout << "ppi address through r: " << &r << std::endl; // reference is not an object so returns address of ppi instead
    
    std::cout << "\nThe value of ival\n"
              << "direct value: " << ival << "\n"
              << "indirect value: " << *pi << "\n"
              << "doubly indirect value: " << **ppi
              << std::endl;
    return 0;
}