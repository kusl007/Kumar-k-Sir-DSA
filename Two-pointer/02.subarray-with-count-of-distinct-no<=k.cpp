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
 
 
    ll sum = 0 ;
    unordered_map <ll,ll> g ; 
    for (int i = 0, j = 0; j < n; j++) {
            g[b[j]]=g[b[j]]+1; //[i............j]
            ll d = g.size();
            while (d>k){
                g[b[i]] = g[b[i]] - 1;
                if(g[b[i]]==0){
                    g.erase(b[i]);
                }
                i++;
                
                d = g.size();
                
            }
            count += (j - i + 1);
 
 
    }
 
    cout<<count;
    return 0;
}