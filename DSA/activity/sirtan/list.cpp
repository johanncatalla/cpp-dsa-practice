#include <iostream>
#include <windows.h>
#include "list.h"

list::list(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->array = new int[capacity];
}

list::~list() {
    delete[] array;
}

void list::display() const {

    std::cout << "Array elements: [";
    for (int i = 0; i < size; i++) {
        std::cout << array[i];
        if (i != size-1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

bool list::replace(int newNum, int index) {
    if (index < 0 || index >= size) {
        return false; // Invalid index
    }
    array[index] = newNum;
    return true;
}

int list::access(int index) const {
    if (index < 0 || index >= size) {
        return -1; // Invalid index
    }
    return array[index];
}

bool list::append(int val) {
    if (size >= capacity) {
        return false; // List is full
    }
    array[size++] = val;
    return true;
}

int list::getElement(int index) const {
    return array[index];
}

int list::getSize() const {
    return size;
}
