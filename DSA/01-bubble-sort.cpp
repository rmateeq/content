#include <iostream>
using namespace std;

#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {           // (n - 1) times
        for (int j = 0; j < n - i - 1; ++j) {   // (n - i - 1) times
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int size = 5;
    int arr[size] = {5, 2, 9, 1, 5};

    bubbleSort(arr, size);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
