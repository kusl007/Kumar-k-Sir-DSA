#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int e=10;
    vector<int>spf(e+1);
    // spf[0]=0;
    // spf[1]=1;
    for(int i=2;i<=e;i++){
        spf[i]=i;
    }
    
   for(int i=2;i<=sqrt(e);i++){
       if(spf[i]==i){
           
           for(int j=i*i;j<=e;j=j+i){
               spf[j]=i;
           }
       }
   }
    
    
    for(int i=0;i<e+1;i++){
        
            cout<<"The smallest prime factor of "<<i<<" is -> " <<spf[i]<<" "<<endl;
        
    }
}