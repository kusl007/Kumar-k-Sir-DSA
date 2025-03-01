#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input size of the array (excluding b[0])
    
    vector<int> b(n + 1, 0);  // Initialize the b array of size n + 1, with all elements 0
    map<int, int> k;  // Map to store frequency of elements

    // Input array b (index 1 to n)
    for (int i = 1; i <= n; i++) {
        cin >> b[i];  // Input each element of b
    }

    // Count frequency of each element in b
    for (int i = 1; i <= n; i++) {
        k[b[i]] += 1;  // Increment frequency of b[i] in map k
    }

    // Create a vector of pairs to store (element, frequency)
    vector<pair<int, int>> g;
    for (auto u : k) {
        g.push_back({u.first, u.second});  // Insert element and its frequency into vector g
    }

    int size = g.size();
    int step = 0;  // Initialize step variable to 0

    // Traverse the vector g backward and calculate the steps
    for (int i = size - 1; i >= 1; i--) {
        g[i - 1].second += g[i].second;  // Add frequency of g[i] to g[i-1]
        step += g[i].second;  // Increment step by the frequency of g[i]
        g[i].second = 0;  // Reset frequency of g[i] to 0
    }

    // Output the result
    cout << step << endl;

    return 0;
}
