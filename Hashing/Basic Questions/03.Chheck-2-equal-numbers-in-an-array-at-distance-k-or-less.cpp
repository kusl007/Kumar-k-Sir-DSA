#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    cout << "Enter the size of the array" << endl;
    int n;
    cin >> n;

    cout << "Enter the array" << endl;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k" << endl;
    int k;
    cin >> k;

    unordered_map<int, int> lastIndex;

    for (int i = 0; i < n; i++) {
        // Check if the element has been seen before
        if (lastIndex.find(arr[i]) != lastIndex.end()) {
            // Check if the difference in indices is within k
            if (i - lastIndex[arr[i]] <= k) {
                cout << "The answer is " << arr[i] << endl;
                 
            }
        }
        // Update the last seen index for the element
        lastIndex[arr[i]] = i;
    }

    cout << "No such element found" << endl;
    return 0;
}
