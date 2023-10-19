#include <iostream>
#include <string>
#include "Queue.h"

int main() {
    int choice;
    std::string mainMenu = "y";
    Queue queue(10);

    while (mainMenu=="y" && choice != 4) {
        queue.printMenu();
        queue.gotoxy(22, 10);
        std::cin >> choice;
        if (choice == 1) {
            system("cls");
            queue.display();
        } else if (choice == 2) {
            system("cls");
            int pushNum;
            std::string contPush = "y";
            while (contPush=="y") {
                std::cout << "Enter number to ENQUEUE: ";
                std::cin >> pushNum;
                queue.enqueue(pushNum);
                std::cout << "Queue: ";
                queue.display();
                std::cout << "\nContinue pushing? [y/n]: ";
                std::cin >> contPush;
                if (contPush!="y") {
                    break;
                }
            }
        } else if (choice == 3) {
            system("cls");
            queue.dequeue();
            std::cout << "New queue:      ";
            queue.display();
        } else {
            break;
        }
        std::cout << "\nGo back to main menu? [y/n]: ";
        std::cin >> mainMenu;
        std::cout << std::endl;
        if (mainMenu != "y") {
            break;
        } else {
            system("cls");
        }
    }
    return 0;
}
