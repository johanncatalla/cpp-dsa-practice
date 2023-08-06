#include <string>
class Car {
private:
    int year;
    int miles;
    std::string make;
public:
    // Member intitializer list syntax
    Car(const int year, const int miles, const std::string &make) : year{year}, miles{miles}, make{make} {}
};

int main()
{
    Car toyota{2001, 100, "Model1"};
}