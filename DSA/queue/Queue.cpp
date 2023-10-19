#include <iostream>
#include <windows.h>
#include "Queue.h"

Queue::Queue(int size) {
    maxSize = size;
    arr = new int[maxSize];
    di = -1;
    ii = -1;
}

Queue::~Queue() {
    delete[] arr;
}

bool Queue::isEmpty() {
    return di == -1 && ii == -1;
}

bool Queue::isFull() {
    return (ii + 1) % maxSize == di;
}

void Queue::enqueue(int value) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue " << value << std::endl;
        return;
    }

    if (isEmpty()) {
        di = ii = 0;
    } else {
        ii = (ii + 1) % maxSize;
    }

    arr[ii] = value;
    std::cout << value << " enqueued to the queue." << std::endl;
}

void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return;
    }

    std::cout << arr[di] << " DEQUEUED from the queue." << std::endl;
    std::cout << "Original queue: ";
    Queue::display();
    if (di == ii) {
        di = ii = -1;
    } else {
        di = (di + 1) % maxSize;
    }
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "[ ";
    int i = di;
    do {
        if (i == ii) {
            std::cout << arr[i] << " ";
        } else {
            std::cout << arr[i] << "->";
        }

        i = (i + 1) % maxSize;
    } while (i != (ii + 1) % maxSize);

    std::cout << "]" << std::endl;
}

void Queue::gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Queue::printMenu() {
    std::cout << char(201);
    for (int i = 0; i <= 34; i++) {
        std::cout << char(205);
    }
    std::cout << char(187) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 4; i++) {
        if (i == 2) {
            std::cout << "NAME: CATALLA, JOHANN SEBASTIAN";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 0; i <= 34; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 6; i++) {
        if (i == 3) {
            std::cout << "QUEUE IMPLEMENTATION IN ARRAY";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 0; i <= 34; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 25; i++) {
        if (i == 12) {
            std::cout << "1: DISPLAY";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 25; i++) {
        if (i == 12) {
            std::cout << "2: ENQUEUE";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 25; i++) {
        if (i == 12) {
            std::cout << "3: DEQUEUE";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 28; i++) {
        if (i == 12) {
            std::cout << "4: EXIT";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 0; i <= 34; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 27; i++) {
        if (i == 13) {
            std::cout << "CHOOSE: ";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(200);
    for (int i = 0; i <= 34; i++) {
        std::cout << char(205);
    }
    std::cout << char(188) << std::endl;
}