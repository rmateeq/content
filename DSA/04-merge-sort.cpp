#include <iostream>
using namespace std;

#include <iostream>

void merge(int arr[], int left, int middle, int right) {
    const int n1 = middle - left + 1;
    const int n2 = right - middle;

    // Create temporary arrays
    int LeftSubarray[n1];
    int RightSubarray[n2];

    // Copy data to temporary arrays LeftSubarray[] and RightSubarray[]
    for (int i = 0; i < n1; i++)
        LeftSubarray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        RightSubarray[j] = arr[middle + 1 + j];

    // Merge the two sub-arrays back into the original array
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (LeftSubarray[i] <= RightSubarray[j]) {
            arr[k] = LeftSubarray[i];
            i++;
        } else {
            arr[k] = RightSubarray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of LeftSubarray[], if any
    while (i < n1) {
        arr[k] = LeftSubarray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of RightSubarray[], if any
    while (j < n2) {
        arr[k] = RightSubarray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    const int size = 6;
    int arr[size] = {64, 25, 12, 22, 11, 1};

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Merge Sort
    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
