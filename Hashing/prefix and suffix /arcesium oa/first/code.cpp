


#include<bits/stdc++.h>
using namespace std ; 
typedef long long int ll ; 


bool check(string x,string y){

    ll i = 0 ; 
    unordered_map <char,ll> map1,map2,map3,map4 ; 
    while(i<x.size()){
        
        char g = x[i];
        
        if(i%2==0){
            map1[g]=map1[g]+1;
        }
        
        else{
            
            map2[g] = map2[g] + 1;
        }
        
        i++;
    }
    
    i = 0 ; 
    while(i<y.size()){
        
        char g = y[i];
        
        if(i%2==0){
            map3[g]=map3[g]+1;
        }
        
        else{
            
            map4[g] = map4[g] + 1;
        }
        
        i++;
    }
  
    if(map1==map3 && map2==map4){
        return true ; 
    }
    
    
    return false ; 
    
}





int main(){
    
    ll n  ; 
    cin>>n;
    vector <string> s1,s5; 
    ll i = 1 ; 
    while(i<=n){
        
        string a; 
        cin>>a;
        s1.push_back(a);
        //cout<<'\n';
        i++;
    }
    
    cin>>n;
    i = 1 ; 
    while(i<=n){
        
        string b; 
        cin>>b;
        s5.push_back(b);
        //cout<<'\n';
        i++;
    }
    
    
    i = 0 ; 
    while(i<n){
        
        if(check(s1[i],s5[i])==true){
            cout<<"Yes";
        }
        
        else {
            cout<<"No";
        }
        cout<<'\n';
        
        i++;
    }
    
    
    
    
    return 0 ; 
}