#include <iostream>
#include <vector>
#include "queue.h"
using namespace std;

Queue::Queue(int size) {
    maxSize = size;
    values = (int*) malloc(sizeof(int) * size);
    queueFront = values;
    queueEnd = values -1; //start with the queueEnd at -1, this will ensure the first Enqueue stats at the beginning of the allocated memory, rather than one address later
    cout << "allocated " << sizeof(int) * size << " bytes at " << values << "\n";
};

void Queue::Enqueue(int value) {
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

int Queue::Dequeue() {
    if (IsEmpty()){
        throw std::runtime_error("Queue is empty and cannot be popped");
    }

    int value = *queueFront; // get the value of the current front of the queue
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

bool Queue::IsEmpty() {
    return currentSize == 0;
}


bool Queue::IsFull() {
    return currentSize == maxSize;
}