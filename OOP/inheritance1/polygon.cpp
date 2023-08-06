// Class definition
// Extends the declaration by providing actual implementation
#include <string>
#include "polygon.h"

// Constructor 
// Must scope the method definitions with the class name (Polygon:)
// Memeber initializer list
Polygon::Polygon(const int num_sides, const std::string name) : num_sides(num_sides), name(name) {}

// long method
/*
Polygon::Polygon(const int num_sides, const std::string name) {
    this->num_sides = num_sides;
    this->name = name;
}
*/

// Get the number of sides

int Polygon::GetNumSides(void) const {
    return this->num_sides;
} 

void Polygon::SetNumSides(const int num_sides) {
    this->num_sides = num_sides;
}

std::string Polygon::GetName(void) const{
    return this->name;
}
void Polygon::SetName(const std::string & name) {
    this->name = name;
}
