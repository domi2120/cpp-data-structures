#include <iostream>
using namespace std;
#pragma once

// a circular queue
template <typename T>
class Queue {

    public:
    Queue(int size);
    ~Queue();
    void Enqueue(T i);
    T Dequeue();
    bool IsEmpty();
    bool IsFull();

    private:
    T* values;
    int currentSize;
    int maxSize;
    T* queueFront;
    T* queueEnd;
};