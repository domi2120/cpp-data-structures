#include <iostream>
using namespace std;
#pragma once

template <typename T>
class Stack
{
    public:
    Stack(int size);
    ~Stack();
    void Push(T i);
    T Pop();
    bool IsEmpty();
    bool IsFull();

    private:
    T* values;
    int currentSize;
    int maxSize;
};