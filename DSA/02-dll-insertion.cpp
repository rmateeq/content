#include <iostream>
using namespace std;

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to create a new node
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head; // Make next of new node as head
    if (head != nullptr) {
        head->prev = newNode; // Move the prev of head node to new node
    }
    head = newNode; // Move the head to point to the new node
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    if (head == nullptr) {
        head = newNode; // If the list is empty, make the new node as head
        return;
    }
    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next; // Traverse till the last node
    }
    lastNode->next = newNode; // Change the next of last node
    newNode->prev = lastNode; // Make last node as previous of new node
}

// Function to insert a node after a given node
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be nullptr" << endl;
        return;
    }
    Node* newNode = new Node(newData);
    newNode->next = prevNode->next; // Make next of new node as next of prevNode
    prevNode->next = newNode; // Make the next of prevNode as newNode
    newNode->prev = prevNode; // Make prevNode as previous of newNode

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode; // Change previous of newNode's next node
    }
}

// Function to insert a new node before a specific node
void insertBefore(Node*& head, Node* nextNode, int newData) {
    if (nextNode == nullptr) {
        cout << "The given next node cannot be nullptr" << endl;
        return;
    }
    Node* newNode = new Node(newData);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    } else {
        head = newNode; // If the nextNode is head, then update the head to newNode
    }
}

// Helper function to print the contents of the doubly linked list
void printList(Node* node) {
    Node* last = nullptr;
    cout << "Traversal in forward direction: ";
    while (node != nullptr) {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << endl;

    cout << "Traversal in reverse direction: ";
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Start with the empty list

    insertAtBeginning(head, 10); // List: 10
    insertAtEnd(head, 20);       // List: 10 <-> 20
    insertAtEnd(head, 30);       // List: 10 <-> 20 <-> 30
    insertAtBeginning(head, 5);  // List: 5 <-> 10 <-> 20 <-> 30

    Node* secondNode = head->next; // Assuming secondNode points to the node with data 10
    insertAfter(secondNode, 15);   // List: 5 <-> 10 <-> 15 <-> 20 <-> 30

    Node* thirdNode = secondNode->next; // Node with data 15
    insertBefore(head, thirdNode, 12);  // List: 5 <-> 10 <-> 12 <-> 15 <-> 20 <-> 30

    cout << "Created DLL is: " << endl;
    printList(head);

    return 0;
}
