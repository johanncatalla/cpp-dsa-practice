//
// Created by admin on 10/19/2023.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


class Queue {
private:
    int* arr;
    int di;
    int ii;
    int maxSize;
public:
    Queue(int size);
    ~Queue();

    bool isEmpty();
    bool isFull();
    void enqueue(int value);
    void dequeue();
    void display();
    void gotoxy(short x, short y);
    void printMenu();
};


#endif //QUEUE_QUEUE_H
