#include <iostream>

class Foo {
private:
    int data;
public:
    // Default constructor (no parameter)
    Foo() : data(0) {}

    // Single argument constructor
    explicit Foo(const int v) : data(v) {}

    // Copy constructor (Foo object as argument)
    Foo(const Foo &f) : data(f.data) {}

    // Copy assignment operator
    Foo &operator=(const Foo &f) {
        data = f.data;
        return *this;
    }

    // Constant functions will not modify members (ideal for getters)
    int getData(void) const {
        return data;
    }
}; 

// Implementation
int main()
{
    // Default Constructor
    Foo obj;

    // Single Argument Constructor
    Foo obj1(10);

    // Copy constructor with Foo object as argument
    Foo obj2(obj1);

    // Copy assignment operator
    obj = obj1;

    std::cout << "obj: " << obj.getData()
              << "\nobj1: " << obj1.getData()
              << "\nobj2: " << obj2.getData()
              << std::endl;
    return 0;
}