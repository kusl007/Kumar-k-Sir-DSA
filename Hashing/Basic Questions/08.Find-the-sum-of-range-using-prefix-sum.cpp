
//must find the sum in a range
#include    <iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int sum =0;
    cout<<"Enter the range index left and right"<<endl;
    int left,right;
    cin>>left>>right;
    for(int i=left;i<=right;i++){
        sum+=arr[i];
    }
    cout<<"the sum is "<<sum<<endl;
}