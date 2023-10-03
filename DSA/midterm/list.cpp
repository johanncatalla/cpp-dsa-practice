#include <iostream>
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

    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << array[i];
        if (i != size-1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void list::replace(int newNum, int index) {
    array[index] = newNum;
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

int list::getCapacity() const {
    return capacity;
}

void list::insert(int num, int index) {
    std::cout << "\n" << num << " inserted to index " << index << std::endl;
    std::cout << "Original Array: ";
    list::display();
    for (int i = size; i > index; --i) {
        array[i] = array[i - 1];
    }
    array[index] = num;
    ++size;
    std::cout << "New Array:      ";
    list::display();
}

bool list::del(int index) {
    if (index >= 0 && index < size) {
        std::cout << "Index " << index << " deleted from array.\n";
        std::cout << "\nOriginal Array: ";
        list::display();
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i+1];
        }
        --size;
        std::cout << "New Array:      ";
        list::display();
        return true;
    } else {
        return false;
    }
}

bool list::search(int num) const {
    for (int i = 0; i < this->size; i++) {
        if (num == array[i]) {
            std::cout << "\n";
            list::display();
            std::cout << num << " found in index " << i << std::endl;
            return true;
        }
    }
    return false;
}

void list::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
