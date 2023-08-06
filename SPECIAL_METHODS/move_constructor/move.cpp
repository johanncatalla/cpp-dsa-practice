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

class Movable {
private: 
    Foo *data_ptr;
public:
    Movable(Foo data) : data_ptr(new Foo(data)) {}

    // Move constructor
    Movable(Movable && m) {
        // Point to the other object's data
        data_ptr = m.data_ptr;

        // Remove the other object's data pointer
        // by setting it to nunllptr
        m.data_ptr = nullptr;
    }

    // Move assignment operator
    Movable &operator=(Movable && m) {
        data_ptr = m.data_ptr;
        m.data_ptr = nullptr;
        return *this;
    }

    auto getPtr(void) const {
        return *data_ptr;
    }

    // Destructor
    ~Movable() {
        delete data_ptr;
    }
};

// implementation
Movable Bar() {
    Foo data(10);
    return data;
}

int main()
{
    Movable a(Bar());
    Movable b = Bar();
    auto x =  a.getPtr();
    return 0;
}