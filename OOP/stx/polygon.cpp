// Class definition
// Extends the declaration by providing actual implementation

#include <string>
#include "polygon.hpp"

// Constructor 
// Must scope the method definitions with the class name (Polygon:)
Polygon::Polygon(const int num_sides, const std::string & name) {
    this->num_sides = num_sides; // 'this is a pointer to the instance of the class. Members are accessed via the -> operator
    this->name = name; // In this case we need to use 'this->' ti avoid shadowing the member variable since the argument shares the same name
}

// Get the number of sides
int Polygon::GetNumSides(void) const {
    return this->num_sides;
} 

void Polygon::SetNumSides(const int num_sides) {
    this->num_sides = num_sides;
}

std::string & Polygon::GetName(void) const{
    return this->name;
}
void Polygon::SetName(const std::string & name) {
    this->name = name;
}
