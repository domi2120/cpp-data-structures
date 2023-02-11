
#include "stack.h"
#include "queue.h"

int TestStack() {

    Stack* b = new Stack(5);

    int counter = 0;

    while (!b->IsFull()) {
        b->Push(counter++);
    }

    cout << "\n";

    while (!b->IsEmpty()) {
        b->Pop();
    }

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
    return 0;
}

int main() {
    
    TestStack();
    TestQueue();
    return 0;
}
