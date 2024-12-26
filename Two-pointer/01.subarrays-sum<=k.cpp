#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin>>n;
    ll k;cin>>k;
    ll b[n];
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }ll count = 0 ;
 
 
    ll sum = 0 ;
    for (int i = 0, j = 0; j < n; j++) {
            sum = sum + b[j]; //[............]
            while (sum>k){
                sum = sum - b[i];
                i++;
            }
            count += (j - i + 1);
 
 
    }
 
    cout<<count;
    return 0;
}