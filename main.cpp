
#include "stack.h"
#include "queue.h"

int TestStack() {

    Stack<long>* stack = new Stack<long>(5);

    long counter = INT32_MAX - 5;

    while (!stack->IsFull()) {
        stack->Push(counter++);
    }

    cout << "\n";

    while (!stack->IsEmpty()) {
        stack->Pop();
    }

    delete stack;
    return 0;
}

int TestQueue() {
    Queue<long>* queue = new Queue<long>(3);
    long counter = __INT_MAX__;

    queue->Enqueue(counter++);
    queue->Enqueue(counter++);
    queue->Enqueue(counter++);
    queue->Dequeue();
    queue->Enqueue(counter++);
    queue->Dequeue();
    queue->Dequeue();
    queue->Dequeue();

    delete queue;
    return 0;
}

int main() {
    TestStack();
    TestQueue();
    return 0;
}
