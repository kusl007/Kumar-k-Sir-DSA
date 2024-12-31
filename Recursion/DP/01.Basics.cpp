#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 

int main() {
    ll n ; 
    cin>>n ; 
    ll a[n+1] ; //1-based indexing..
    
    ll i = 1 ;
    while(i<=n){
        cin>>a[i] ; 
        i++;
    }
    
    //1--->dp[]
    
    ll dp[n+1]={0}; 
    
    dp[1] = a[1] ; 
    dp[2] = a[1] + a[2] ; //base-cases..
    
    i = 3 ; 
    while(i<=n){
        dp[i] = dp[i-1] + a[i] ; 
        i++;
    }
    
    //This took O(N) and we calculated all the required dp values..
    
    ll q;
    cin>>q;
    i = 1 ; 
    while(i<=q){
        ll index ; 
        cin>>index ; 
        cout<<dp[index] ; //O(1)
        cout<<"\n";
        i++;
    }
    //O(Q) time
    
    //O(N+Q)====>TOTAL_TIME!!!!
    
    
    
    
    return 0 ; 
}

/*

5
1 2 3 4 5
5
2
3
4
5
1

*/