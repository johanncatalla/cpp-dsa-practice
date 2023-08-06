// dynamic allocation
#include <iostream>
int main()
{
    // Intitialize pointer to null
    int *p = nullptr;
    
    // Request memory using new operator
    p = new(std::nothrow) int;
    if (!p)
        std::cout << "allcoation failed" << std::endl;
    else
    {
        // Store the value 
        *p = 29;
        std::cout << "Value of p: " << *p << std::endl;
    }

    // Request memory
    float *r = new float(3.14);
    std::cout << "Value of r: " << *r << std::endl;

    int n = 5;
    int *q = new(std::nothrow) int[n];
    
    if (!q)
        std::cout << "allocation failed" << std::endl;
    else
    {
        // initialize array using iteration
        for (int i = 0; i < n; i++)
            q[i] = i+1;

        std::cout << "Value stored in block of memory: ";
        for (int i = 0; i < n; i++)
            std::cout << q[i] << ",";
    }

    // Free allocated memory
    delete p;
    delete r;

    // Free block of allocated memory
    delete[] q;

    return 0;
}