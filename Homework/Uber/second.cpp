// Given an array of size “N”; you have to find maximum subarray sum. 

// -> O(N) -> Kadane’s algorithm solves the problem. 

// -> You are allowed to do 1 special operation before finding the maximum subarray sum. 

// -> Select any range [l...r] and multiply it with x. 

// -> Then find the maximum subarray sum possible 

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& arr, int x) {
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[1][0] = max(0, arr[1]);
    dp[1][1] = max(0, x * arr[1]);

    vector<int> kSum(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        kSum[i] = max(0, max(arr[i], arr[i] + kSum[i - 1]));
    }

    int ans = max(dp[1][0], dp[1][1]);
    for (int i = 2; i < n; ++i) {
        dp[i][1] = max(0, max(arr[i] * x, max(arr[i] * x + dp[i - 1][1], arr[i] * x + kSum[i - 1])));
        dp[i][0] = max(0, max(arr[i], max(arr[i] + kSum[i - 1], max(arr[i] + dp[i - 1][1], arr[i] + dp[i - 1][0]))));

        ans = max(ans, max(dp[i][1], dp[i][0]));
    }

    return ans;
}

int main()
{
    // ignore the 0th index
    vector<int> arr = {-11, -1, -2, 3, 4, 5, -13, 7, 8};
    int x = -1;

    cout << maxSubarraySum(arr, x) << endl;
    return 0;
}
