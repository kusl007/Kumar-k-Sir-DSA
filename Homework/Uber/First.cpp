#include<bits/stdc++.h>
using namespace std;

// Given two arrays; a and b -> you can start at index 1 from any array and end your journey at index n on an array 

// -> If you are at i you can can jump to i+1 on same array or different array 

// -> -1000000000 <= a[i], b[i] <= 10000000000 

// -> Please output total number of journeys which have even sum and total number of journeys which have odd sum;

void solve(vector<int>& a, vector<int>& b, int n) {
    vector<int> dpa_e(n, 0);
    vector<int> dpa_o(n, 0);

    vector<int> dpb_e(n, 0);
    vector<int> dpb_o(n, 0);

    dpa_e[0] = (a[0] % 2 == 0) ? 1 : 0;
    dpa_o[0] = (a[0] % 2 == 0) ? 0 : 1;
    dpb_e[0] = (b[0] % 2 == 0) ? 1 : 0;
    dpb_o[0] = (b[0] % 2 == 0) ? 0 : 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] % 2 == 0) {
            dpa_e[i] = dpa_e[i - 1] + dpb_e[i - 1];
            dpa_o[i] = dpa_o[i - 1] + dpb_o[i - 1];
        } else {
            dpa_e[i] = dpa_o[i - 1] + dpb_o[i - 1];
            dpa_o[i] = dpa_e[i - 1] + dpb_e[i - 1];
        }

        if (b[i] % 2 == 0) {
            dpb_e[i] = dpa_e[i - 1] + dpb_e[i - 1];
            dpb_o[i] = dpa_o[i - 1] + dpb_o[i - 1];
        } else {
            dpb_e[i] = dpa_o[i - 1] + dpb_o[i - 1];
            dpb_o[i] = dpa_e[i - 1] + dpb_e[i - 1];
        }
    }

    cout << "Total Even Journeys: " << dpa_e[n - 1] + dpb_e[n - 1] << "\n";
    cout << "Total Odd Journeys: " << dpa_o[n - 1] + dpb_o[n - 1] << "\n";

    return;
}

int main()
{
    int n = 3;
    vector<int> a = {1,2,3};
    vector<int> b = {2,2,4};
    
    solve(a, b, n);
    
    return 0;
}