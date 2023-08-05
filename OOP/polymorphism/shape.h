#include <cmath>

class Shape {
public:
    // Virtual destructor
    virtual ~Shape() {}

    // Virtual area method
    virtual double Area() const {
        return 0.0;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    // Constructor using a member initializer list instead of assignment in the method body
    Rectangle(const double w, const double l) : width(w), length(l) {}

    // Compute the area of the rectangle
    // Override the Shape::Area() method with an implementation specific to Rectangle
    double Area(void) const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    explicit Circle(double r) : radius(r) {}

    // Override the Shape::Area() method with an implementation specific to Circle
    //
    // NOTE: there is an 'override' keyword that was introduced in C++11 and is optional: it is used
    // to enforce that the method is indeed an overriding method of a virtual base method at compile time
    // and is used as follows:
    // Compute the area of a circle
    double Area(void) const override {
        return M_PI * radius * radius; // pi*r^2
    }
};
