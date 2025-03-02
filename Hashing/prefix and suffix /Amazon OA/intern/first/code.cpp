#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    
    string s, t; 
    
    cin>>s>>t;
    
    
    unordered_map<char, ll> mp1, mp2; // for s & t
    
    for(int i=0; i<s.size(); i++) mp1[s[i]]++;
    
    for(int i=0; i<t.size(); i++) mp2[t[i]]++; 
    
    
    ll cnt=1e9; 
    
    for(int i=0; i<t.size(); i++) 
    {
        if(mp1.find(t[i])==mp1.end()) 
        {
            // it means t[i] is not present in s hence we will not get any subset 
            
            return 0; 
        }
        
        ll val =  mp1[t[i]]/mp2[t[i]];
        
        // cout<<val<<" ";
        
        cnt = min(cnt, val); 
    }
    
    
    cout<<cnt<<" ";
    
    
    
    return 0;
}