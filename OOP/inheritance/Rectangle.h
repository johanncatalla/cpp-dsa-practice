#include <string>

#include "polygon.h"

// We extend from Polygon by using the colon (:) and specifying which type of inheritance
// will be used (public inheritance, in this case)

class Rectangle : public Polygon {
    private:
        int length;
        int width;
        // <--- NOTE: The member variables 'num_sides' and 'name' are already inherited from Polygon
        //            it's as if we sort of get them for free, since we are a sub-class
    public:
        explicit Rectangle(const std::string &name);
        Rectangle(const std::string &name, const int length, const int width);

        // Getters and Setters
        const int GetLength(void);
        void SetLength(const int);

        const int GetWidth(void);
        void SetWidth(const int);
        // <--- NOTE: Again, the getters/setters for 'num_sides' and 'name' are already inehrited from Polygon

        // Other methods
        const int Area(void) const;
};      
