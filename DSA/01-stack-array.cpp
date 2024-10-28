#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int element) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = element;
    }

    // Function to remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Function to return the top element of the stack
    int peek() const {
        if (!isEmpty()) {
            return arr[top];
        } else {
            cout << "Stack is empty\n";
            return -1;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() const {
        return top == capacity - 1;
    }
};

// Demo usage of the stack
int main() {
    Stack stack(3);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "The top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "The top element is: " << stack.peek() << endl;

    stack.pop();

    if (stack.isEmpty()) {
        cout << "The stack is empty\n";
    } else {
        cout << "The stack is not empty\n";
    }

    return 0;
}