#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin>>n;
    ll k;cin>>k;
    ll b[n];
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }ll p = 0 ;
    
    
    ll sum = 0 ;
    for (int i = 0, j = 0; j < n; j++) {
            sum = sum + b[j]; //[............]
            while (sum>k){
                sum = sum - b[i];
                i++;
            }
            ll length = (j-i+1) ; //sum[i.....j] <= k -> checking its length. 
            
            
            p = max(p,length);
            
    }

    
    cout<<p;
    return 0;
}//RRRRR