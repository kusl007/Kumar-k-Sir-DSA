#include <iostream>
#include <unordered_map>
using namespace std;
 
int main() {
    int n, q;
    cout<<"enter the size of array"<<endl;
    cin >> n;
    unordered_map<int, int> hash_map;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        hash_map[array[i]] = hash_map[array[i]] + 1;
    }
 
    cin >> q;
 
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
 
        int count = hash_map[query];
        cout << count << endl;
    }
 
    return 0;
}