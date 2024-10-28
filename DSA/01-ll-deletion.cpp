#include <iostream>
using namespace std;

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
        cout << current->data << " ";
        
        // Move to the next node
        current = current->next;
    }
    cout << endl;
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
        cout << "Invalid position\n";
        return;
    }

    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete the first node of the list
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) return; // Empty list, nothing to delete

    Node* temp = head; // Store the current head node in a temporary variable
    head = head->next; // Update the head to the next node
    delete temp; // Deallocate the former head node
}

// Function to delete the last node of the list
void deleteAtEnd(Node*& head) {
    if (head == nullptr) return; // Empty list, nothing to delete

    // If there is only one node, delete it and update the head to nullptr
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Traverse to the second-to-last node
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    // Delete the last node and update the second-to-last node's next to nullptr
    delete current->next;
    current->next = nullptr;
}

// Function to delete a node at a specific position
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr || position < 0) return; // Invalid position or empty list

    Node* current = head;
    if (position == 0) { // Delete the first node
        head = head->next;
        delete current;
        return;
    }

    // Traverse to the node before the one to delete
    for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }

    // If the position is beyond the end of the list
    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    // Perform the deletion
    Node* temp = current->next; // Node to delete
    current->next = current->next->next; // Bypass the deleted node
    delete temp; // Deallocate the node
}

int main() {
    // Initialize an empty linked list
    Node* head = nullptr;

    // Insert nodes into the linked list to prepare for demonstration
    insertAtBeginning(head, 10);  // List: 10
    insertAtEnd(head, 20);        // List: 10 -> 20
    insertAtEnd(head, 30);        // List: 10 -> 20 -> 30
    insertAtPosition(head, 2, 25);// List: 10 -> 20 -> 25 -> 30
    insertAtEnd(head, 40);        // List: 10 -> 20 -> 25 -> 30 -> 40

    cout << "Initial list: ";
    traverseLinkedList(head);     // Expected: 10 -> 20 -> 25 -> 30 -> 40

    // Demonstrate deletion at the beginning
    deleteAtBeginning(head);
    cout << "After deleting at the beginning: ";
    traverseLinkedList(head);     // Expected: 20 -> 25 -> 30 -> 40

    // Demonstrate deletion at the end
    deleteAtEnd(head);
    cout << "After deleting at the end: ";
    traverseLinkedList(head);     // Expected: 20 -> 25 -> 30

    // Demonstrate deletion at a specific position (e.g., position 1)
    deleteAtPosition(head, 1);
    cout << "After deleting at position 1: ";
    traverseLinkedList(head);     // Expected: 20 -> 30

    // Clean up memory by deallocating remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}