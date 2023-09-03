#include <iostream>
#include <map>

int main() {
    std::map<int, int> customers;
    int customerCnt;

    std::cout << "Enter the number of customers: ";
    std::cin >> customerCnt;

    // map definition
    for (int i = 0; i < customerCnt; i++) {
        int num = 0;
        std::cout << "Customer number: ";
        std::cin >> num;
        if (customers.find(num) == customers.end()) {
            customers[num] = 1;
        } else {
            customers[num] += 1;
        }
    }
    bool dupes = false;
    for (const auto& pair : customers) {
        if (pair.second != 1) dupes = true;
    }
    if (dupes == false) {
        std::cout << "\nHONEST CUSTOMERS";
    } else {
        std::cout << "\nDuplicates:\n";
        for (const auto& pair : customers) {
            if (pair.second != 1) std::cout << "Customer #" << pair.first << std::endl;
        }
    }

    return 0;
}
