#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;  // Input the size of the array and the two integers x and y
    vector<int> b(n + 1, 0);  // Array of size n + 1, initialized to 0

    // Input the array
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    long long count = 0;  // Count of valid subarrays
    unordered_map<int, int> freq;  // HashMap to store the frequency of d values
    freq[0] = 1;  // Base case: d = 0 has been achieved once

    int cx = 0, cy = 0;  // Counters for x and y

    // Loop through the array
    for (int i = 1; i <= n; i++) {
        // Update counters based on the value of b[i]
        if (b[i] == x) {  // Check if b[i] is equal to x
            cx++;
        } else if (b[i] == y) {  // Check if b[i] is equal to y
            cy++;
        }

        int d = cx - cy;  // Calculate d
        count += freq[d];  // Increment count based on how many times d was achieved
        freq[d]++;  // Update frequency of d
        cout<<"the freq of" << d <<"is " <<freq[d]<<endl;
        cout<<"the count is " << count <<endl;

    }

    cout << count << endl;  // Output the count
    return 0;
}
