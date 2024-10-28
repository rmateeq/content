#include <iostream>
using namespace std;

int main() {
    // Initialize variables
    int* dynamicArray = nullptr;  // Pointer for dynamic array
    int size = 0;                 // Current size of the dynamic array
    int capacity = 5;             // Initial capacity

    // Allocate memory for the initial dynamic array
    dynamicArray = new int[capacity];

    // Function to print the elements of the dynamic array
    auto printArray = [&]() {
        cout << "Dynamic Array: ";
        for (int i = 0; i < size; ++i) {
            cout << dynamicArray[i] << " ";
        }
        cout << "\n";
    };

    // Function to resize the dynamic array
    auto resizeArray = [&](int newCapacity) {
        int* newArray = new int[newCapacity];  // Allocate a new array with the new capacity

        // Copy elements from the old array to the new array
        for (int i = 0; i < size; ++i) {
            newArray[i] = dynamicArray[i];
        }

        // Deallocate memory for the old array
        delete[] dynamicArray;

        // Update the pointer to point to the new array
        dynamicArray = newArray;

        // Update the capacity
        capacity = newCapacity;
    };

    // Add elements to the dynamic array
    for (int i = 1; i <= 10; ++i) {
        // Check if resizing is needed
        if (size == capacity) {
            // Double the capacity when resizing is needed
            resizeArray(2 * capacity);
        }

        // Add the element to the dynamic array
        dynamicArray[size++] = i;

        // Print the dynamic array after each addition
        printArray();
    }

    // Deallocate memory for the dynamic array
    delete[] dynamicArray;

    return 0;
}
