#include <iostream>
using namespace std;

int     calculatePower(int n,int p){
    if(p==0){
        return 1;
    }
    return n*calculatePower(n,p-1);
}

int main(){
    int n=2;
    int p=3;
    int ans=calculatePower(n,p);
    cout<<"the "<<p<<"th power of "<<n<<" is "<<ans;
}