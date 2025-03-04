#include <iostream>

using namespace std;

int main() {
    int n, Q, p;
    cin >> n >> Q >> p;

    int b[100001] = {0}; // Assuming l, r <= 100000

    for (int i = 1; i <= Q; i++) {
        int L, R;
        cin >> L >> R;
        b[L] = b[L] + 1;

        if (R + 1 <= n) {
            b[R + 1] = b[R + 1] - 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        b[i] = b[i] + b[i - 1];
    }

    for (int i = 1; i <= p; i++) {
        int y;
        cin >> y;
        cout << b[y] << endl;
    }

    return 0;
}
