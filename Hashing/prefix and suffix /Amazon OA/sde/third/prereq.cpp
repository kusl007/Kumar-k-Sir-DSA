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
    for (int i = 0, j = n-1; i<n; i++) {
        ll d = b[j] + b[i]; //[i............j]
        while (d>k && i!=j){
            j--;
            d = b[j] + b[i];
 
        }
        if(i==j){break;
        }
        cout<<i<<" "<<j;
        cout<<"\n";
        count += (j - i);
    }
    cout<<(count);
    return 0;
}//RRRRR