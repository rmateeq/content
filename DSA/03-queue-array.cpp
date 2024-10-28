#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    const int capacity;
    int* queue;

public:
    CircularQueue(int capacity) : capacity(capacity), front(-1), rear(-1), size(0) {
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return false;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int item = queue[front];
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return item;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }
};

int main() {
    CircularQueue q(5); // Creating a circular queue with capacity of 5

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.enqueue(6);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
