#include <iostream>
#include "storage.h"

// Usage
int main() {
    Container<int> a(1);
    Container<float> b(3.14f);
    Container<int> c(a);

    std::cout << a.getData() << std::endl;
    std::cout << b.getData() << std::endl;
    std::cout << c.getData();
}