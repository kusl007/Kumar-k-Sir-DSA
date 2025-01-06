#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


int findMaxMedian(vector<int> v){
    int n=v.size();
    int count=n/3;

    int ans=0;
    for(int i=n-2;i>=0;i=i-2){
      if(count>0){
          
        ans+=v[i];
        count--;
      }
      else{
        break;
      }
    }
    return ans;
    
    
}

int  main(){
    vector<int> v={1,2,3,4,6,7,5,8,9,10};
    sort(v.begin(),v.end());
    int ans=findMaxMedian(v);
    cout<<"the max median is "<<ans<<endl;

}