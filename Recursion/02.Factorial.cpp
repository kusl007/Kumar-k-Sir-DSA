#include <iostream>
using namespace std;

int     calculateFactorial(int n){
    if(n==0){
        return 1;
    }
    return n*calculateFactorial(n-1);
}

int main(){
    int n=5;
    int ans=calculateFactorial(n);;
    cout<<"the factorial of "<<n<<" is "<<ans;
}