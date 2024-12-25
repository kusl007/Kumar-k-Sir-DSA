#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countPairsWithDifference(vector<int>& b, int k) {
    unordered_map<int, int> freq; // To store the frequency of each element
    int count = 0;

    // Traverse the array
    for (int num : b) {
        // Check for both (num - k) and (num + k)
        if (freq.find(num - k) != freq.end()) {
            count += freq[num - k];
        }
        if (freq.find(num + k) != freq.end()) {
            count += freq[num + k];
        }

        // Update the frequency of the current number
        freq[num]++;
    }

    return count;
}

int main() {
    vector<int> b = {1, 5, 3, 4, 2}; // Example input
    int k = 2; // Target difference
    cout << "Count of pairs: " << countPairsWithDifference(b, k) << endl;
    return 0;
}
