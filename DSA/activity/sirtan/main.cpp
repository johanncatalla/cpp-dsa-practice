#include <iostream>
#include "list.h"
#include <functional>
#include <unordered_map>
#include <string>

void printMenu() {
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+";
    std::cout << "\n+ CHOOSE AND OPERATION: +" << std::endl;
    std::cout << "+      1. Display       +"
              << "\n+      2. Replace       +"
              << "\n+      3. Access        +"
              << "\n+      4. Append        +"
              << "\n+      5. Exit          +\n"
              <<"+-+-+-+-+-+-+-+-+-+-+-+-+" << std::endl;
}

int main() {
    list myList(10);
    std::unordered_map<int, std::function<void(list&)>> functionMap;
    functionMap[1] = [](list& myList) { myList.display(); };
    functionMap[2] = [](list& myList) {
        int idx, newNum, oldNum;
        bool replace;
        std::cout << "Enter index to replace: ";
        std::cin >> idx;
        oldNum = myList.getElement(idx);
        std::cout << "Enter new number: ";
        std::cin >> newNum;
        replace = myList.replace(newNum, idx);
        if (!replace) {
            std::cout << "Index out of range.\n";
        } else {
            std::cout << "Index " << idx << "(" << oldNum << ") replaced with (" << newNum << ")" << std::endl;
        }

    };
    functionMap[3] = [](list& myList) {
        int idx, size;
        std::cout << "Enter index to access: ";
        std::cin >> idx;
        size = myList.getSize();
        if (idx <= size) {
            int num = myList.access(idx);
            std::cout << "Index " << idx << ": " << num;
        } else {
            std::cout << "Index out of range.";
        }

    };
    functionMap[4] = [](list& myList) {
        int append, size;
        std::string contAppend = "y";
        while (contAppend == "y" || contAppend == "Y") {
            std::cout << "Enter number to append: ";
            std::cin >> append;
            myList.append(append);
            size = myList.getSize();
            std::cout << append << " appended to index " << size-1 << std::endl;
            std::cout << "\nAppend another value? [y/n]: ";
            std::cin >> contAppend;
            if (contAppend == "n" || contAppend == "N") {
                break;
            }
        }
    };

    int choice = 0;
    std::string mainMenu = "y";
    while (mainMenu=="y" && choice != 5) {
        printMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        if (choice == 5) {
            break;
        }
        std::cin.ignore();
        system("cls");
        if (functionMap.find(choice) != functionMap.end()) {
            functionMap[choice](myList);
        }
        std::cout << "\nGo back to main menu? [y/n]: ";
        std::cin >> mainMenu;
        std::cout << std::endl;
        if (mainMenu != "y") {
            break;
        }
        system("cls");
    }
    return 0;
}