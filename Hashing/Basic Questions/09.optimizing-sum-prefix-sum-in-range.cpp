
//must find the sum in a range
#include    <iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int sum =0;
    cout<<"Enter the range index left and right"<<endl;
    int left,right;
    cin>>left>>right;
    unordered_map<int,int>prefix;
    prefix[0]=arr[0];
    for(int i=1;i<10;i++){
       prefix[i]=prefix[i-1]+arr[i];
    }
    cout<<"the sum is "<<prefix[right]-prefix[left-1]<<endl;
    cout<<"the right is "<<prefix[right]<<endl;
    cout<<"the left is "<<prefix[left]<<endl;
}