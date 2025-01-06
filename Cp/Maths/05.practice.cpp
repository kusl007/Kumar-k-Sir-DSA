#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


vector<int>calculateSPF(int e){
     vector<int>spf(e+1);
    spf[0]=0;
    spf[1]=1;
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
   return spf;
}


vector<int> calculatePrime(int num,vector<int>spf){
    vector<int>ans;
    
    while(num!=1){
        ans.push_back(spf[num]);
       num=num/spf[num];
        
        
           
    }
    return ans;
}
int main() {
    int e = 100;
    vector<int> spf = calculateSPF(e);
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

    for (auto num : arr) {
        if (num == 1) {
            cout << "The number 1 has no prime factors." << endl;
            continue;
        }
        vector<int> ans = calculatePrime(num, spf);
        cout << "The prime factors of " << num << " are: ";
        for (size_t j = 0; j < ans.size(); j++) {
            cout << ans[j];
            if (j < ans.size() - 1) cout << " x ";
        }
        cout << endl;
    }

    return 0;
}