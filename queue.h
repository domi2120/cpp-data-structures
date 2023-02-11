#include <iostream>
using namespace std;
#pragma once

// a circular queue
class Queue {

    public:
    Queue(int size);
    ~Queue();
    void Enqueue(int i);
    int Dequeue();
    bool IsEmpty();
    bool IsFull();

    private:
    int* values;
    int currentSize;
    int maxSize;
    int* queueFront;
    int* queueEnd;
};