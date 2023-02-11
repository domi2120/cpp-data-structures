
#include "stack.h"

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

int main() {
    
    TestStack();
    return 0;
}
