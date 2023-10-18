#include <iostream>
#include "list.h"
#include <functional>
#include <unordered_map>
#include <string>
#include <windows.h>

// Function Definition
void gotoXY(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printMenu() {
    std::cout << "CATALLA" << std::endl;
    std::cout << char(201);
    for (int i = 0; i <= 21; i++) {
        std::cout << char(205);
    }
    std::cout << char(187) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 18; i++) {
        if (i == 9) {
            std::cout << "MENU";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 0; i <= 21; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 12; i++) {
        if (i == 6) {
            std::cout << "1: DISPLAY";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 12; i++) {
        if (i == 6) {
            std::cout << "2: REPLACE";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 13; i++) {
        if (i == 6) {
            std::cout << "3: ACCESS";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 13; i++) {
        if (i == 6) {
            std::cout << "4: APPEND";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 13; i++) {
        if (i == 6) {
            std::cout << "5: INSERT";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 13; i++) {
        if (i == 6) {
            std::cout << "6: DELETE";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 13; i++) {
        if (i == 6) {
            std::cout << "7: SEARCH";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 15; i++) {
        if (i == 6) {
            std::cout << "8: SORT";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 15; i++) {
        if (i == 6) {
            std::cout << "9: EXIT";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;

    std::cout << char(204);
    for (int i = 0; i <= 21; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
}

int main() {
    int capacity;
    std::cout << "Enter list capacity: ";
    std::cin >> capacity;
    list myList(capacity);
    system("cls");
    std::unordered_map<int, std::function<void(list&)>> functionMap;
    functionMap[1] = [](list& myList) {
        std::cout << "Array: ";
        myList.display();
    };
    functionMap[2] = [](list& myList) {
        int idx, newNum, oldNum, size;
        std::cout << "Enter index to replace: ";
        std::cin >> idx;
        oldNum = myList.getElement(idx);
        size = myList.getSize();
        if (size==0) {
            std::cout << "List is empty\n";
        } else if (idx <= size-1 && idx >= 0) {
            std::cout << "Enter new number: ";
            std::cin >> newNum;
            myList.replace(newNum, idx);
        } else {
            std::cout << "Index out of range.\n";
        }
    };
    functionMap[3] = [](list& myList) {
        int idx, size;
        std::cout << "Enter index to access: ";
        std::cin >> idx;
        size = myList.getSize();
        if (size==0) {
            std::cout << "List is empty.\n";
        } else if (idx <= size) {
            int num = myList.access(idx);
            std::cout << "Index " << idx << ": " << num << std::endl;
        } else {
            std::cout << "Index out of range.\n";
        }

    };
    functionMap[4] = [&capacity](list& myList) {
        int append, size;
        std::string contAppend = "y";
        while (contAppend == "y" || contAppend == "Y") {
            if (size == capacity) {
                std::cout << "Array is full" << std::endl;
                break;
            }
            std::cout << "Enter number to append: ";
            std::cin >> append;
            myList.append(append);
            size = myList.getSize();
            std::cout << append << " appended to index " << size-1 << std::endl;
            myList.display();
            std::cout << "\nAppend another value? [y/n]: ";
            std::cin >> contAppend;
            if (contAppend == "n" || contAppend == "N") {
                break;
            }
        }
    };
    functionMap[5] = [](list& myList) {
        int num, idx;
        std::cout << "Enter position to insert into: ";
        std::cin >> idx;
        if (idx < 0 || idx >= myList.getSize()) {
            std::cout << "Invalid Index" << std::endl;
        } else if (myList.getSize() >= myList.getCapacity()) {
            std::cout << "Array is full." << std::endl;
        } else {
            std::cout << "Enter number to insert: ";
            std::cin >> num;
            myList.insert(num, idx);
        }
    };
    functionMap[6] = [](list& myList) {
        int idx;
        std::cout << "Enter index to delete: ";
        std::cin >> idx;

        bool verifyDel = myList.del(idx);
        if (!verifyDel) {
            std::cout << "Index out of range.";
        }
    };
    functionMap[7] = [](list& myList) {
        int num;
        std::cout << "Enter number to search: ";
        std::cin >> num;

        bool verifyNum = myList.search(num);
        if (!verifyNum) {
            std::cout << "\n";
            myList.display();
            std::cout << num << " not found in array.\n";
        }
    };
    functionMap[8] = [](list& myList) {
        std::cout << "Original Array: ";
        myList.display();
        myList.sort();
        std::cout << "Sorted Array:   ";
        myList.display();
    };

    int choice = 0;
    std::string mainMenu = "y";
    while (mainMenu=="y" && choice != 9) {
        printMenu();
        std::cout << char(186);
        for (int i = 0; i <= 14; i++) {
            if (i == 6) {
                std::cout << "CHOOSE: ";
            } else {
                std::cout << " ";
            }
        }
        std::cout << char(186) << std::endl;
        std::cout << char(200);
        for (int i = 0; i <= 21; i++) {
            std::cout << char(205);
        }
        std::cout << char(188) << std::endl;

        gotoXY(15, 14);
        std::cin >> choice;

        if (choice == 9) {
            break;
        }

        std::cin.ignore();
        system("cls");

        if (functionMap.find(choice) != functionMap.end()) {
            functionMap[choice](myList);
        } else {
            std::cout << "Invalid choice." << std::endl;
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



