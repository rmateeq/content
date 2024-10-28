#include <iostream>
using namespace std;

//Function Signatures
int binarySearch(int arr[], int low, int high, int key);

int main() {
    const int size = 15;
    int sortedArray[size] = {2, 5, 8, 12, 16, 23, 38, 42, 45, 67, 77, 87, 91, 93, 216};

    int keyToSearch = 116;
    int result = binarySearch(sortedArray, 0, size - 1, keyToSearch);

    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}

int binarySearch(int arr[], int low, int high, int key) {
    int comp = 0;
    while (low <= high) {
        cout<< "Comparison #: " << ++comp << endl;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Key not found
}
