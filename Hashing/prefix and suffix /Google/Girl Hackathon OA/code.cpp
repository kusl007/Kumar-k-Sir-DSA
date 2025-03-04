#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 


int main() {
    ll n ; 
    cin>>n ;
    ll a[n+1];
    ll k ; 
    cin>>k; 
    ll i = 1 ; 
    while(i<=n){
        cin>>a[i];
        i++;
    }
    
    ll b[200005] = {0};
    i = 1 ;
    while(i<=n){
        ll l = a[i] - k ;
        ll r = a[i] + k ;
        b[l] = b[l] + 1 ;  
        b[r+1] = b[r+1] - 1 ;  
        i = i + 1 ; 
    }
    ll answer = 1 ;   
    i = 1 ;  
    while(i<=200000){
        b[i] = b[i-1] + b[i]; 
        //cout<<b[i]<<"\n";
        answer = max(b[i],answer) ; 
        i = i + 1 ;
    }
    cout<<answer ; 
    return 0 ; 
}