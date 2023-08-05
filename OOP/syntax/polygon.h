// Header file or class declaration
#include <string>

class Polygon {
    // Private members and methods are only accessible via methods in the class definition
    private:
        int num_sides;
    
    // Protected members and methods are only  accessible in the class definition or by classes who extend this class
    protected:
        std::string name;

    // Public members and methods are accessible to anuone who creates an instance of the class
    public:
        Polygon(const int num_sides, const std::string name); // Constructor or order of parameters

        // Getters and setters
        int GetNumSides(void) const;
        void SetNumSides(const int num_sides);
        
        std::string GetName(void) const;
        void SetName(const std::string & name);
};