#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &A, int B) {
    int n = A.size();

    // Compute Prefix Sum Array
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + A[i];
    }

    // Compute Suffix Sum Array
    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = A[i] + suff[i + 1];
    }

    // Find Maximum Sum using Prefix & Suffix
    int ans = suff[n - B]; // Case where we take only last B elements
    for (int i = 0; i < B; i++) {
        int prefSum = pref[i + 1];         // Sum of first (i+1) elements
        int suffSum = suff[n - B + (i + 1)]; // Remaining elements from end
        ans = max(ans, prefSum + suffSum);
    }

    return ans;
}

int main() {
    vector<int> A = {1, 2, 3, 11, 12, 13, 3, 2, 5, 8, 1, 7, 6};
    int B = 3;
    cout << "Maximum sum by picking " << B << " elements: " << maxSum(A, B) << endl;
    return 0;
}
