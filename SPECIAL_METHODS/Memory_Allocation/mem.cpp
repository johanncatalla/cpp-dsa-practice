#include <iostream>

int *p = new int(69);
float *q = new float(3.14);
    
// Custom datatype
struct cust
{
    int p; 
    cust(int q) : p(q) {}
    cust() = default;
};

int main()
{
    cust *var1 = new cust(66);
    cust *vart = new cust(25);
    
    std::cout << var1->p << std::endl;
    std::cout << vart->p << std::endl;

    delete var1, delete vart;

    // deleted
    std::cout << vart->p;

    return 0;
}
