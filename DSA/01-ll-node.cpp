#include <iostream>

// Define the structure for a node in the linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
};

int main() {
    // Example of creating a linked list node
    Node* newNode = new Node; // Allocate memory for a new node
    newNode->data = 10;       // Assign a value to the data component
    newNode->next = nullptr;  // Initialize the next pointer to null (end of list)
    
    // Output the data stored in the node
    std::cout << "Data in the node: " << newNode->data << std::endl;

    // Deallocate memory for the node
    delete newNode;

    return 0;
}
