#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

template <class T>
Stack<T>::Stack(int size) {
    maxSize = size;
    values = (T*) malloc(sizeof(T) * size);
    cout << "allocated " << sizeof(T) * size << " bytes at " << values << "\n";
};

template <class T>
Stack<T>::~Stack() {
    free(values);
}

template <class T>
void Stack<T>::Push(T i) {
    if (IsFull()){
        throw std::runtime_error("Stack exceeded maximum size");
    }
    T* nextAddress = (values + currentSize);
    *nextAddress = i;
    cout << "currentSize: " << currentSize << " pushed value: " << i << " to address: " << nextAddress << "\n"; 
    currentSize++;
}

template <class T>
T Stack<T>::Pop() {
    if (IsEmpty()){
        throw std::runtime_error("Stack is empty and cannot be popped");
    }
    // since size doesn't start from 0, a size of 1 means only the first slot is filled. So we subtract -1 from the size
    T* endAddress = (values + currentSize - 1 );
    T value = *endAddress;
    cout << "currentSize: " << currentSize << " popped value: " << value << " from address: " << endAddress << "\n"; 
    currentSize--;
    return value;
}

template <class T>
bool Stack<T>::IsEmpty() {
    return currentSize == 0;
}

template <class T>
bool Stack<T>::IsFull() {
    return currentSize == maxSize;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<long>;