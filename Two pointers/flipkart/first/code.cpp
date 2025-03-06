#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int v = 0;
    int i = 0, j = 0;
    unordered_map<int, int> k;

    while (i < n && j < n) {
        if (k.find(b[j]) == k.end()) {
            k[b[j]] = j;
            int l = j - i + 1;
            v = max(v, l);
            j++;
        } else {
            int id = k[b[j]];
            while (i <= id) {
                k.erase(b[i]);
                i++;
            }
            i = id + 1;
            k[b[j]] = j;
            j++;
        }
    }

    cout << v << endl;
    return 0;
}
