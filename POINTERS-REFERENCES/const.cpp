#include <iostream>
int main()
{
    const double pi = 3.14;
    // The address of a const object can only be stored in a pointer to const
    const double *cptr = &pi;
    
    // The address of a nonconst object can be stored in a pointer to but cannot be modified usign that pointer
    // *cpr = 12; will return error
    // However, we can reassign another address to the const pointer
    int k = 111;
    int j = 123;
    const int *cpr = &j;
    cpr = &k;

    // However, a pointer is also an object so we can also make it a const itself.
    // In this pointer, we cannot change the value of the object we are pointing to and 
    // we cannot change the address the pointer is assigned.
    const int *const pnter = &j;

    std::cout << pnter;
    return 0;
}