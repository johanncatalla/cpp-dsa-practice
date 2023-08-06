// File: complex.h
#include <iostream>
class Complex {
private:
    double r = 0.0; // Real part, defaults to 0.0
    double i = 0.0; // Imaginary part, defaults to 0.0

public:
    Complex(const double r, const double i) : r(r), i(i) {}

    // + Operator (declaration only)
    friend Complex operator+(const Complex &a, const Complex &b);

    // - Operator (declaration only)
    friend Complex operator-(const Complex &a, const Complex &b);

    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
};

// These are NOT member functions
// They can also be defined inside the class body but leaving them outside
// is a clearer reminder that they are not part of the class
Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.r + b.r, a.i + b.i);
}

Complex operator-(const Complex &a, const Complex &b) {
    return Complex(a.r - b.r, a.i - b.i);
}

// Definition
// Again, this is not a member function
std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << c.r << " + " << c.i << "i";
    return os;
}