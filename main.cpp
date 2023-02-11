
#include "stack.h"
#include "queue.h"

int TestStack() {

    Stack* stack = new Stack(5);

    int counter = 0;

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
    Queue* queue = new Queue(3);
    int counter = 0;

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
