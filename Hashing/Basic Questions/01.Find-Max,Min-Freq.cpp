#include <iostream>
#include    <unordered_map>
#include    <vector>
#include <limits>
using namespace std;


int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int,int> mp;
    int maxi=INT_MIN;
    int mini=INT_MAX;
    int minElement,maxElement;
    for(int i=0;i<n;i++){
        cout<<"enter the elements of array"<<endl;
        cin>>arr[i];
        mp[arr[i]]++;
      
    }
    for (auto it : mp) {
        if (it.second > maxi) {
            maxi = it.second;
            maxElement = it.first;
        }
        if (it.second < mini) {
            mini = it.second;
            minElement = it.first;
        }
    }
    
    cout<<"the max element is "<<maxElement<<endl;
    cout<<"the max frequency is "<<maxi<<endl;
    cout<<"the min element is "<<minElement<<endl;
    cout<<"the min frequency is "<<mini<<endl;

    for(auto it:mp){
        cout<<it.first<<" : "<<it.second<<endl;
    }
    return 0;
}