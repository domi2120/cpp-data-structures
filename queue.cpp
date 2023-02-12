#include <iostream>
#include <vector>
#include "queue.h"
using namespace std;

template <class T>
Queue<T>::Queue(int size) {
    maxSize = size;
    values = (T*) malloc(sizeof(T) * size);
    queueFront = values;
    queueEnd = values -1; //start with the queueEnd at -1, this will ensure the first Enqueue stats at the beginning of the allocated memory, rather than one address later
    cout << "allocated " << sizeof(T) * size << " bytes at " << values << "\n";
};

template <class T>
Queue<T>::~Queue() {
    free(values);
}

template <class T>
void Queue<T>::Enqueue(T value) {
    if (IsFull()){
        throw std::runtime_error("Queue exceeded maximum size");
    }

    if (queueEnd == values + maxSize -1) {
        // queueEnd has reached the end of the allocated memory, set it to the beginning of the underlying memory block
        queueEnd = values;
    } else {
        // as long as we're not at the end of the allocated memory, move queueEnd one address further
        queueEnd = queueEnd + 1;
    }

    *queueEnd = value; // set enqueued value at the current end of the queue
    cout << "currentSize: " << currentSize << " enqueued value: " << value << " to address: " << queueEnd << " QueueEnd: " << queueEnd << " QueueFront: " << queueFront << "\n";
    currentSize++; // increase the size counter
}

template <class T>
T Queue<T>::Dequeue() {
    if (IsEmpty()){
        throw std::runtime_error("Queue is empty and cannot be popped");
    }

    T value = *queueFront; // get the value of the current front of the queue
    cout << "currentSize: " << currentSize << " dequeued value: " << value << " from address: " << queueFront << " QueueEnd: " << queueEnd << " QueueFront: " << queueFront << "\n";
    
    if (queueFront == values + maxSize -1)
    {
        // the queueFront has reached the end of the allocated memory, set it to the beginning of underlying memory block.
        queueFront = values;
    } else {
        // as long as we're not at the end of the allocated memory, move queueFront one address further
        queueFront = queueFront + 1;
    }
    
    currentSize--; // decrease the size counter
    return value;
}

template <class T>
bool Queue<T>::IsEmpty() {
    return currentSize == 0;
}


template <class T>
bool Queue<T>::IsFull() {
    return currentSize == maxSize;
}

template class Queue <int>;
template class Queue <float>;
template class Queue <long>;