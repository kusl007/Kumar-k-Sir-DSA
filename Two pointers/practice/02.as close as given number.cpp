// https://docs.google.com/document/d/13sbEeg9c3NT1cMfyichvK2WOF4pv8yWaSrWXRnQOM44/edit?tab=t.0
//https://drive.google.com/file/d/1np3wQTtqGt0HAPXHpBXxW9Y3HzmSf9oP/view


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ; 
    cin>>n ; 
    int a[n+1] = {0};
    int b[n+1] = {0};
    
    int i = 1 ; 
    while(i<=n){
        cin>>a[i];
        i++;
    }
    
    i = 1 ; 
    while(i<=n){
        cin>>b[i];
        i++;
    }
    
    int y ; 
    cin>>y ; 
    int first = 0 ; 
    int second = 0 ; 
    int v = 0 ; 
    int j = n ; 
    i = 1 ;
    int kk = 0 ; 
    while(i<=n && j>=1){
        
       if(a[i]+b[j]<=y){
           
           int sum = a[i] + b[j] ; 
           if(sum>v){
               v = sum ; 
               first = a[i];
               second = b[j] ; 
           }
           
           i = i + 1 ; 
       }
       
       else {
           j = j - 1 ; 
           
       }
        
        
    }
    cout<<v;
    cout<<'\n';
    return 0 ; 
}
/*
4
1 4 5 7 
10 20 30 40 
32
*/




