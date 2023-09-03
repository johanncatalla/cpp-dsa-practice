#include <iostream>
#include <string>
#include <cmath>

struct Person {
    std::string name;
    int age;
};

int main() {
    int numPeople;
    std::cout << "Enter the number of people: ";
    std::cin >> numPeople;

    Person people[numPeople];

    int sum = 0;
    for (int i = 0; i < numPeople; i++) {
        Person person;
        std::cout << "Enter name of person " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, person.name);
        std::cout << "Enter age of person " << i+1 << ": ";
        std::cin >> person.age;
        people[i] = person;
        sum += person.age;
    }

    double avg = static_cast<double>(sum) / numPeople;
    std::cout << "The average age of the people is " << static_cast<int>(std::round(avg));

    return 0;
}