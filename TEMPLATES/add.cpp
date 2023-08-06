#include "complex.h"

template <typename T> // T becomes whatever type is used at compile-time
T Add(const T &a, const T &b) {
    return a + b; // The type T must support the + operator
}

int main() {
    std::cout << Add<int>(3,5) << std::endl; // int version
    std::cout << Add<double>(3.2, 5.8) << std::endl; // double
    std::cout << Add(3.4f, 5.0f) << std::endl; // implicit float version: we leave off the <float> here, since it can deduce the type from the context

    Complex a {1, 2};
    Complex b {5, 3};
    std::cout << Add(a, b); // Works because we added support for the + operator
}