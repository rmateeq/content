#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& list, int target) {
	int comp = 0;
    for (int i = 0; i < list.size(); ++i) {
    	cout<<"Comparison #: " << ++comp << endl;
        if (list[i] == target) {
            return i;  // Return the index if target is found
        }
    }
    return -1;  // Return -1 if target is not found
}

int main() {
    vector<int> myList = {10, 4, 7, 2, 5, 8};
    int targetValue = 9;

    int result = linearSearch(myList, targetValue);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the list." << endl;
    }

    return 0;
}