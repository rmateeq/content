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
    cout<< head->data<<endl;
    cout<< head->next<<endl;

    // Traverse the list until reaching the end (nullptr)
    while (current != nullptr) {
        // Output the data stored in the current node
        std::cout << current->data << " ";
        
        // Move to the next node
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example of creating a linked list
    Node* head = new Node;      // Head node
    head->data = 10;            // Assign a value to the data component
    head->next = nullptr;       // Initialize the next pointer to null (end of list)

    // Create additional nodes
    Node* second = new Node;
    second->data = 20;
    second->next = nullptr;

    Node* third = new Node;
    third->data = 30;
    third->next = nullptr;

    // Link the nodes together
    head->next = second;
    second->next = third;

    // Traverse the linked list and print its elements
    traverseLinkedList(head);

    // Clean up memory by deallocating nodes
    delete head;
    delete second;
    delete third;

    return 0;
}
