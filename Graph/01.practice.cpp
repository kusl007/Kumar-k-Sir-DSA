#include <iostream>
using namespace std;
 int arr[1000][1000];
int main(){
      cout << "Enter the number of nodes and edges: " << endl;


    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        cout<<"enter the value of edges like if from 2->1 and 1->2 use 1 2"<<endl;
        int x,y;
        cin>>x>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                sum++;
            }
        }
        cout<< i << "contains " <<" "<<sum<<"edges"<<endl;
    }
    return 0;
}