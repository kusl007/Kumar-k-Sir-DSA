#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#define MOD 1000000007
#define MAX_A 100000

using namespace std;

// Compute SPF (Smallest Prime Factor) using sieve
vector<int> computeSPF(int max_val) {
    vector<int> spf(max_val + 1);
    for (int i = 0; i <= max_val; i++) spf[i] = i;

    for (int i = 2; i * i <= max_val; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= max_val; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

// Prime factorization using SPF
unordered_map<int, int> primeFactorization(int num, const vector<int>& spf) {
    unordered_map<int, int> factors;
    while (num != 1) {
        int prime = spf[num];
        factors[prime]++;
        num /= prime;
    }
    return factors;
}

// Prime factorization of M!
unordered_map<int, int> factorialPrimeFactors(int m, const vector<int>& spf) {
    unordered_map<int, int> factorization;
    for (int i = 2; i <= m; i++) {
        unordered_map<int, int> factors = primeFactorization(i, spf);
        for (const auto& [prime, exp] : factors) {
            factorization[prime] += exp;
        }
    }
    return factorization;
}

// Calculate divisors modulo MOD
long long calculateDivisors(const unordered_map<int, int>& factors) {
    long long divisors = 1;
    for (const auto& [prime, exp] : factors) {
        divisors = divisors * (exp + 1) % MOD;
    }
    return divisors;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Compute SPF for numbers up to MAX_A
    vector<int> spf = computeSPF(MAX_A);

    // Compute prime factorization of M!
    unordered_map<int, int> mFactorialFactors = factorialPrimeFactors(M, spf);

    // Calculate F(Bi) for each Ai
    for (int num : A) {
        unordered_map<int, int> numFactors = primeFactorization(num, spf);
        unordered_map<int, int> combinedFactors = mFactorialFactors;

        // Merge factors of num and M!
        for (const auto& [prime, exp] : numFactors) {
            combinedFactors[prime] += exp;
        }

        // Calculate divisors and print result
        cout << calculateDivisors(combinedFactors) << " ";
    }
    cout << endl;

    return 0;
}
