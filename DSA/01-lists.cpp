#include <iostream>
#include <string>
#include <stdexcept> // For out_of_range
using namespace std;

template <typename T>
class PythonList {
private:
    T* elements; // Pointer to the elements array
    int capacity; // Total capacity of the list
    int count; // Number of elements currently in the list

public:
    PythonList() : elements(nullptr), capacity(0), count(0) {}

    ~PythonList() {
        delete[] elements; // Free the allocated memory
    }

    void append(const T& value) {
        if (count == capacity) {
            // Resize the array if there's no space left
            int newCapacity = capacity == 0 ? 1 : capacity * 2;
            T* newElements = new T[newCapacity];
            for (int i = 0; i < count; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
        elements[count++] = value; // Add the new element and increment the count
    }

    T& operator[](int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Index out of range");
        }
        return elements[index]; // Return the element at the given index
    }

    int size() const {
        return count; // Return the number of elements in the list
    }
};


int main() {
    // Create an instance of MyContainer for integers
    MyContainer<int> intContainer(5);
    for (int i = 0; i < 5; ++i) {
        intContainer[i] = i * 10; // Use the overloaded [] operator to store values
    }

    // Print the integers from the container
    cout << "Integers in container: ";
    for (int i = 0; i < 5; ++i) {
        cout << intContainer[i] << " "; // Use the overloaded [] operator to access values
    }
    cout << endl;

    // Create an instance of MyContainer for string
    MyContainer<string> stringContainer(3);
    stringContainer[0] = "Hello";
    stringContainer[1] = ", ";
    stringContainer[2] = "World!";

    // Concatenate and print the strings from the container
    cout << "String in container: ";
    for (int i = 0; i < 3; ++i) {
        cout << stringContainer[i]; // Use the overloaded [] operator to access values
    }
    cout << endl;

    return 0;
}
