//Take the graph; for each node “i” how many nodes are directly connected to it

//n->nodes
//m->edges

//2->1

#include <iostream>

using namespace std;

int b[10000][10000];
int main() {
    
    int n,m;
    cin>>n>>m ; 
    for(int i=1;i<=m;i++){
        //taking input of un-directed graph.
        int x,y; 
        cin>>x>>y;
        //2->1
        //b[2][1]=1;
        //b[1][2]=1; 
        b[x][y] = 1 ; 
        b[y][x] = 1 ; 
    }
    
    
    for(int i=0;i<=n-1;i++){
        int c = 0 ; 
        for(int j=0;j<=n-1;j++){
            
            if(b[i][j]==1){
                c++;
            }
            
        }
        cout<<i<<" "<<c; 
        cout<<"\n";
    }
}