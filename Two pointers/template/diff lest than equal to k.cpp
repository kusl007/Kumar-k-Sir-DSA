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
    }ll count = 0 ;
 
 
    sort(b,b+n);
    for (int i = 0, j = 0; j < n; j++) {
        ll d = b[j] - b[i]; //[i............j]
        while (d>k){
            i++;
            d = b[j] - b[i];
 
        }
        count += (j - i + 1);
    }
    cout<<(count-n);
    return 0;
}//RRRRR