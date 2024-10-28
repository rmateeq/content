#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr) {}
};

// Queue class using a linked list
class Queue {
private:
    Node* front; // Pointer to the front node
    Node* rear;  // Pointer to the rear node

public:
    Queue(): front(nullptr), rear(nullptr) {}

    // Function to add an element to the rear of the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            // If the queue is empty, both front and rear are the new node
            front = rear = newNode;
            return;
        }
        // Add the new node at the end of the queue and change the rear
        rear->next = newNode;
        rear = newNode;
    }

    // Function to remove an element from the front of the queue
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        int data = front->data;
        front = front->next;

        // If the queue becomes empty, update the rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return data;
    }

    // Function to get the element at the front of the queue without removing it
    int peek() const {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Destructor to clear up the queue
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Demo the queue implementation
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue elements after dequeuing one element:" << endl;
    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.dequeue();
    }

    return 0;
}
