#include "Rectangle.h"

// This is called "overloaded constructors" Each constructor can have different parameter lists, 
// Allowing you to create objects in different ways based on the arguments passed.

// This constructor calls the superclass (Polygon) constructor and sets the name and number of sides to '4', and then sets the length and width
Rectangle::Rectangle(const std::string &name, const int length, const int width) : Polygon(4, name) {
    this->length = length;
    this->width = width;
}

// This constructor calls the superclass (Polygon) constructor, but sets the length and width to a constant value
// The explicit keyword is used to restrict the use of the constructor. See section below for more detail
Rectangle::Rectangle(const std::string &name) : Polygon(4, name) {
    this->length = 1;
    this->width = 1;
}

const int Rectangle::GetLength(void) {
    return this->length;
}

void Rectangle::SetLength(const int) {
    this->length = length;
}

const int Rectangle::GetWidth(void) {
    return this->width;
}

void Rectangle::SetWidth(const int) {
    this->width = width;
}

const int Rectangle::Area(void) const {
    return length * width;
}