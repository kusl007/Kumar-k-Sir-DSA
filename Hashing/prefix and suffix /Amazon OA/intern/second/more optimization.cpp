#include <iostream>
#include <vector>
#include <algorithm>

bool function(const std::vector<int>& b, int n) {
    std::vector<int> s(n + 1);
    s[n] = b[n];

    for (int i = n - 1; i >= 1; i--) {
        s[i] = std::max(b[i], s[i + 1]);
    }

    int p = b[1];
    for (int i = 2; i <= n - 1; i++) {
        if (p < b[i] && b[i] < s[i + 1]) {
            return true;
        }
        p = std::min(p, b[i]);
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> b(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }

    bool result = function(b, n);
    std::cout << (result ? "True" : "False") << std::endl;

    return 0;
}
