#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    //e->final point till where prime numbers are to be printed
    int e=100;
    vector<bool>prime(e+1,true);
    prime[0]=false;
    prime[1]=false;
    
    for(int i=2;i<=sqrt(e);++i){
        if (prime[i]==true){
            for(int j=i*i;j<=e;j=j+i){
                prime[j]=false;
                
            }
        }
    }
    
    
    for(int i=0;i<e+1;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
}