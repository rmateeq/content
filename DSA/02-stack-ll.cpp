#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Function to add an element to the top of the stack
    void push(int data) {
        Node* newNode = new Node(data, top);
        top = newNode;
    }

    // Function to remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        }
        Node* temp = top;
        int poppedData = top->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    // Function to return the top element of the stack without removing it
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }
};

// Demo usage of the stack
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "The top element is: " << stack.peek() << endl;

    cout << "Popping elements from the stack: ";
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    if (stack.isEmpty()) {
        cout << "The stack is now empty.\n";
    }

    return 0;
}
