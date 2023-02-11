#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

Stack::Stack(int size) {
    maxSize = size;
    values = (int*) malloc(sizeof(int) * size);
    cout << "allocated " << sizeof(int) * size << " bytes at " << values << "\n";
};

Stack::~Stack() {
    free(values);
}

void Stack::Push(int i) {
    if (IsFull()){
        throw std::runtime_error("Stack exceeded maximum size");
    }
    int* nextAddress = (values + currentSize);
    *nextAddress = i;
    cout << "currentSize: " << currentSize << " pushed value: " << i << " to address: " << nextAddress << "\n"; 
    currentSize++;
}

int Stack::Pop() {
    if (IsEmpty()){
        throw std::runtime_error("Stack is empty and cannot be popped");
    }
    // since size doesn't start from 0, a size of 1 means only the first slot is filled. So we subtract -1 from the size
    int* endAddress = (values + currentSize -1 );
    int value = *endAddress;
    cout << "currentSize: " << currentSize << " popped value: " << value << " from address: " << endAddress << "\n"; 
    currentSize--;
    return value;
}

bool Stack::IsEmpty() {
    return currentSize == 0;
}


bool Stack::IsFull() {
    return currentSize == maxSize;
}