#include <iostream>

int main()
{
    int i = 43;
    int j = 12;
    int *k = &j;
    int **p = &k;
    std::cout << **p << std::endl;
    // 12 because pointer p points to pointer k whick points to j = 12
    k = &i;
    std::cout << **p << std::endl; 
    // becomes 43 because we modified pointer k to point to i = 43 
    **p = 40;
    std::cout << i << std::endl;
    // i is now 40 because we dereferenced p twice which returns the object we are pointing to
    
    int **&r = p; // references pointer p, returns k address when called without dereferencing
    std::cout << "returns address: " << r << std::endl;
    std::cout << "pointer k address: " << &k << std::endl;

    // reference r returns i when dereferenced twice
    std::cout << "r value: " << **r << std::endl;
    std::cout << "i value: " << i << std::endl;
    std::cout << "j value " << j << std::endl;

    **r = j; // assigns the value of j(12) to i
    std::cout << "i value after reassignment: " << i << std::endl;

    std::cout << "Address of i: " << &i << std::endl;
    // pointer p and k still points to i but with a value of 12, we did not reassign the points to j.
    std::cout << *p << std::endl;
    std::cout << k << "\n" << std::endl;

    int *&r2 = k; // references pointer k
    r2 = &j; // reassigns p and k to j
    std::cout << *p << std::endl;
    std::cout << k << std::endl;
    std::cout << "Address of j: " << &j << std::endl;

    int val1 = 111;
    int val2 = 222;
    int *p1 = &val1;
    int **p2 = &p1;

    std::cout << "\np1 address: " << &p1 << std::endl;
    std::cout << "p2 address: " << &p2 << "\n" << std::endl;

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "val1 address: " << &val1 << std::endl;
    std::cout << "val2 address: " << &val2
              << "\nval1: " << val1
              << "\nval2: " << val2 << std::endl;

    p1 = &val2;
    std::cout << "\np1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "val1 address: " << &val1 << std::endl;
    std::cout << "val2 address: " << &val2
              << "\nval1: " << val1
              << "\nval2: " << val2 << std::endl;

    return 0;
}
 