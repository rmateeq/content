#include <iostream>

// Define the structure for a node in the linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
};

// Function to traverse the linked list and print its elements
void traverseLinkedList(Node* head) {
    // Start from the head node
    Node* current = head;

    // Traverse the list until reaching the end (nullptr)
    while (current != nullptr) {
        // Output the data stored in the current node
        std::cout << current->data << " ";
        
        // Move to the next node
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node*& head, int newData) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = newData;
    // Point the new node to the current head
    newNode->next = head;
    // Update the head to point to the new node
    head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node*& head, int newData) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    // If the list is empty, make the new node the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the end of the list
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
}

// Function to insert a new node at any position in the list
void insertAtPosition(Node*& head, int position, int newData) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    // If the position is 0, insert at the beginning
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the node before the position
    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    // Check if the position is valid
    if (current == nullptr) {
        std::cout << "Invalid position\n";
        return;
    }

    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    // Initialize an empty linked list
    Node* head = nullptr;

    // Insert nodes into the linked list
    insertAtBeginning(head, 10); // Insert 10 at the beginning
    insertAtEnd(head, 20);       // Insert 20 at the end
    insertAtPosition(head, 1, 15); // Insert 15 at position 1 (after 10)

    // Traverse the linked list and print its elements
    traverseLinkedList(head);

    // Clean up memory by deallocating nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
