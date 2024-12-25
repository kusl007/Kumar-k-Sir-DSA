#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"enter the array"<<endl;
        cin>>arr[i];
    }
    cout<<"enter the size of query"<<endl;
    int q;
    cin>>q;
    vector<int> queries(q);
    for(int i=0;i<q;i++){
        cout<<"enter the query"<<endl;
        cin>>queries[i];
    }
    cout<<"the count is"<<endl;
    for(int i=0;i<q;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==queries[i]){
                count++;
            }
        }
        cout<< queries[i]<<" : "<<count<<endl;
    }

}