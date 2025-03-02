//calculate max subarray of 2 different subarray in the number

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    vector<int> arr = {1,5,-3,4,-9,9,2};
    int n = arr.size();

    vector<int> ltr(n);
    vector<int> rtl(n);

    // Initialize the first and last elements correctly
    ltr[0] = max(0,arr[0]);
    rtl[n - 1] = max(0,arr[n - 1]);

    // Calculate left-to-right maximum subarray sum
    for (int i = 1; i < n; i++) {
        ltr[i] = max(ltr[i - 1] + arr[i], max(arr[i],0));
    }

    // Calculate right-to-left maximum subarray sum
    for (int i = n - 2; i >= 0; i--) {
        rtl[i] = max(rtl[i + 1] + arr[i], max(arr[i],0));
    }

    int ans = INT_MIN;
    vector<int>mltr(n);
    vector<int>mrtl(n);
    mltr[0]=ltr[0];
    mrtl[n-1]=rtl[n-1];
    

    
    
    for(int i=1;i<n;i++){
        mltr[i]=max(ltr[i],ltr[i-1]);
    }
     for(int i=n-2;i>=0;i--){
        mrtl[i]=max(rtl[i],rtl[i+1]);
    }
    
    

    // Find the maximum sum by removing one element
    for (int i = 0; i < n - 1; i++) {
        int current = mltr[i] + mrtl[i + 1];
        ans = max(ans, current);
    }
    
    
        cout<<"arr"<<endl;
            for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;  cout<<"ltr"<<endl;
            for(auto i:ltr){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:mltr){
        cout<<i<<" ";
    }
    cout<<endl;
    
     cout<<"rtl"<<endl;
            for(auto i:rtl){
        cout<<i<<" ";
    }
    cout<<endl;
        for(auto i:mrtl){
        cout<<i<<" ";
    }
    cout<<endl;

    cout << ans << endl;

    return 0;
}
