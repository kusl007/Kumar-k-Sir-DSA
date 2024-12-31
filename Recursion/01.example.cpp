#include <iostream>

int sumNumbersRecursive(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumNumbersRecursive(n - 1);
    }
}

int main() {
    int n = 5; // Replace 5 with the desired value of N
    int result = sumNumbersRecursive(n);
    std::cout << "The sum of numbers from 0 to " << n << " is: " << result << std::endl;
    return 0;
}
