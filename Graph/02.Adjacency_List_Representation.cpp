#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    int n,m;
    cin>>n>>m ; 
    vector <int> g[n];
    
    for(int i=1;i<=m;i++){
        //taking input of un-directed graph.
        int x,y; 
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    
    for(int i=0;i<=n-1;i++){
        int c = g[i].size() ; 
    
        cout<<i<<" "<<c; 
        cout<<"\n";
    }
}