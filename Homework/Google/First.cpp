// You are given 2 arrays. Choose a subarray from the first array (arr1) and replace it with the corresponding subarray from the second array (arr2). After replacing the subarray, calculate the maximum consecutive subarray sum of the modified first array. Find the maximum subarray sum you can get by doing this operation. You can do this operation only once.

// N is 10^5 and ai [-1e9, 1e9]

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& a1, vector<int>& a2) {
    int n = a1.size();

    vector<int> kSum(n, 0);
    for (int i = 1; i < n; ++i) {
        kSum[i] = max(0, max(a1[i], a1[i] + kSum[i - 1]));
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[1][1] = max(0, a2[1]); // transfer
    dp[1][0] = max(0, a1[1]); // not transfer

    int ans = max(dp[1][1], dp[1][0]);

    for (int i = 2; i < n; ++i) {
        dp[i][1] = max(0, max(a2[i], max(a2[i] + dp[i - 1][1], a2[i] + kSum[i - 1]))); // transfer
        dp[i][0] = max(0, max(a1[i], max(a1[i] + kSum[i - 1], max(a1[i] + dp[i - 1][1], a1[i] + dp[i - 1][0])))); // non transfer

        ans = max(ans, max(dp[i][1], dp[i][0]));
    }

    return ans;
}

int main()
{
    // ignore the 0th index
    vector<int> a1 = {-1000,1,-2,-3,4,-5};
    vector<int> a2 = {-1000,2,3,4,-5,6};
    
    cout << maxSubarraySum(a1, a2) << endl;
    return 0;
}