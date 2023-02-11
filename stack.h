#include <iostream>
using namespace std;
#pragma once

class Stack 
{
    public:
    Stack(int size);
    void Push(int i);
    int Pop();
    bool IsEmpty();
    bool IsFull();

    private:
    int* values;
    int currentSize;
    int maxSize;
};