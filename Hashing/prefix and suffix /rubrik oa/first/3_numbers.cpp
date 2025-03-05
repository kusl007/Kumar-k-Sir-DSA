#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;  // Input the size of the array and the three integers x, y, z
    vector<int> b(n + 1, 0);  // Array of size n + 1

    // Input the array
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    long long count = 0;  // Count of valid subarrays
    map<pair<int, int>, int> freq;  // HashMap to store frequencies of pairs
    freq[{0, 0}] = 1;  // Base case: (d1, d2) has been achieved once

    int cx = 0, cy = 0, cz = 0;  // Counters for x, y, and z

    // Loop through the array
    for (int i = 1; i <= n; i++) {
        // Update counters based on the value of b[i]
        if (b[i] == x) {
            cx++;
        } else if (b[i] == y) {
            cy++;
        } else if (b[i] == z) {
            cz++;
        }

        int d1 = cy - cx;  // First condition difference
        int d2 = cz - cy;  // Second condition difference

        count += freq[{d1, d2}];  // Increment count based on how many times (d1, d2) was achieved
        freq[{d1, d2}]++;  // Update frequency of (d1, d2)
    }

    cout << count << endl;  // Output the count
    return 0;
}
