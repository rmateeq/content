#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a vector with an initial capacity of 5
    vector<int> dynamicVector;

    // Function to print the elements of the dynamic vector
    // Note this is a lambda function used within main()
    // Please try writing it's conventional alternative
    auto printVector = [&]() {
        cout << "Dynamic Vector: ";
        for (const int& element : dynamicVector) {
            cout << element << " ";
        }
        cout << "\n";
    };

    // Add elements to the dynamic vector
    for (int i = 1; i <= 10; ++i) {
        // Add the element to the dynamic vector
        dynamicVector.push_back(i);

        // Print the dynamic vector after each addition
        printVector();
    }

    return 0;
}
