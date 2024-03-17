#include<iostream>
using namespace std;

int main() {
    int soldierCount, boatPasses = 0;
    std::cout << "\nEnter the number of soldiers: ";
    cin >> soldierCount;

    while (soldierCount > 0) {
        // the two boys cross the river
        boatPasses++;

        // one boy returns back
        boatPasses++;

        // One soldier crosses the river
        soldierCount--;
        boatPasses++;

        // One boy goes across the river to bring the boat back
        boatPasses++;
    }

    std::cout << "The boat needs to pass from shore to shore " << boatPasses << " times.\n" << endl;

    return 0;
}
