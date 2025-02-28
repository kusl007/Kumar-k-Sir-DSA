#include <bits/stdc++.h>
using namespace std;

// Easier version of the Question: Given three arrays a, b, and c, at each index you either select a[i], b[i], or c[i]. 
// After making the selections for n elements, we want the sum of all selected elements to be maximized.

int getMaxSum(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n = a.size();
    int maxSum = 0;
    for (int i = 0; i < n; ++i) {
        maxSum += max(a[i], max(b[i], c[i]));
    }
    return maxSum;
}

// Medium Version: Consecutive selection from the same array is not allowed.
int maximizeVacationScore(int n, vector<vector<int>>& activities) {
    vector<int> dpActivityA(n, 0);
    vector<int> dpActivityB(n, 0);
    vector<int> dpActivityC(n, 0);

    dpActivityA[0] = activities[0][0];
    dpActivityB[0] = activities[0][1];
    dpActivityC[0] = activities[0][2];

    for (int i = 1; i < n; ++i) {
        dpActivityA[i] = activities[i][0] + max(dpActivityB[i - 1], dpActivityC[i - 1]);
        dpActivityB[i] = activities[i][1] + max(dpActivityA[i - 1], dpActivityC[i - 1]);
        dpActivityC[i] = activities[i][2] + max(dpActivityB[i - 1], dpActivityA[i - 1]);
    }

    return max(dpActivityA[n - 1], max(dpActivityB[n - 1], dpActivityC[n - 1]));
}

// Hard Version: Consecutive selection from the same array is allowed, but not more than two consecutive selections.
int maximizeVacationScoreWithLimit(int n, vector<vector<int>>& activities) {
    vector<int> dpActivityA(n, 0);
    vector<int> dpActivityB(n, 0);
    vector<int> dpActivityC(n, 0);

    dpActivityA[0] = activities[0][0];
    dpActivityB[0] = activities[0][1];
    dpActivityC[0] = activities[0][2];

    dpActivityA[1] = activities[1][0] + max(dpActivityA[0], max(dpActivityB[0], dpActivityC[0]));
    dpActivityB[1] = activities[1][1] + max(dpActivityA[0], max(dpActivityB[0], dpActivityC[0]));
    dpActivityC[1] = activities[1][2] + max(dpActivityA[0], max(dpActivityB[0], dpActivityC[0]));

    for (int i = 2; i < n; ++i) {
        dpActivityA[i] = max(activities[i][0] + max(dpActivityB[i - 1], dpActivityC[i - 1]),
                             activities[i][0] + activities[i - 1][0] + max(dpActivityB[i - 2], dpActivityC[i - 2]));
        dpActivityB[i] = max(activities[i][1] + max(dpActivityA[i - 1], dpActivityC[i - 1]),
                             activities[i][1] + activities[i - 1][1] + max(dpActivityA[i - 2], dpActivityC[i - 2]));
        dpActivityC[i] = max(activities[i][2] + max(dpActivityB[i - 1], dpActivityA[i - 1]),
                             activities[i][2] + activities[i - 1][2] + max(dpActivityB[i - 2], dpActivityA[i - 2]));
    }

    return max(dpActivityA[n - 1], max(dpActivityB[n - 1], dpActivityC[n - 1]));
}

int main() {
    int n = 10;
    vector<vector<int>> activities = {
         {15, 95, 45},
    {25, 85, 55},
    {35, 75, 65},
    {45, 65, 35},
    {85, 25, 75},
    {55, 55, 50},
    {65, 45, 60},
    {75, 35, 40},
    {95, 15, 70},
    {105, 5, 30}
    };
    
    cout << maximizeVacationScoreWithLimit(n, activities) << "\n";
    
    return 0;
}
