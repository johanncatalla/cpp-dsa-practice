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
    // In this pointer, we can't change the value of the object we are pointing to and 
    // we cannot change the address the pointer is assigned.
    const int *const pnter = &j;

    // Another example is a const pointer to a nonconst object
    // We cannot change the address it is assigned buy we can modify the object it is pointing to
    int *const pnter1 = &k;
    *pnter1 = 666;

    // a pointer should not be uninitialized as it can cause crashes and undefined behavior
    // instead assign it to a valid address or use nullptr as initializer
    int *ptr = nullptr;

    const int ci = 42; // top level
    const int *p2 = &ci; // low-level
    const int *const p3 = p2; // right: = top-level, left = low-level


    std::cout << p2;
    return 0;
}