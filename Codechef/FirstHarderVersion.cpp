#include <bits/stdc++.h>
using namespace std;
typedef int ll;

long long int g;const ll MAXN = 10000000;unordered_map<ll, ll> b1;
const long long int MOD = 1e9 + 7;

vector<ll> spf(MAXN + 1); // Smallest prime factor for each number

// Function to compute the smallest prime factor (SPF) for each number
void computeSPF() {
    for (ll i = 2; i <= MAXN; i++) {
        spf[i] = i;
    }
    for (ll i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

// Function to calculate the prime factorization using the smallest prime factor (SPF)
unordered_map<ll, ll> factorize(ll vl) {
    unordered_map<ll, ll> factors;
    while (vl != 1) {
        ll d = spf[vl];
        factors[d]++;
        vl /= d;
    }
    return factors;
}
long long int modInverse(long long int A, long long int M) {
    long long result = 1;
    long long int exp = M - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result%M * A%M) % M;
        }
        A = (A%M * A%M) % M;
        exp /= 2;
    }
    return result;
}

ll f(ll vl) {
    unordered_map<ll, ll> factors;
    while (vl != 1) {
        ll d = spf[vl];
        factors[d]++;
        vl /= d;
    }
    
    for (auto itr = factors.begin(); itr != factors.end(); ++itr) {
            ll old_count = b1[itr->first];
            ll new_count = old_count + itr->second;
            g = g * (new_count + 1) % MOD;  // Add new count
            
            // Perform modular inverse and multiplication for updating g
            g = g * modInverse(old_count + 1, MOD) % MOD;  // Remove old count
        }
    
    
    return g;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    // Precompute the smallest prime factors for numbers up to MAXN
    computeSPF();

     // Store the factor counts for numbers up to m
    g = 1;

    // Calculate b1 by processing numbers from 2 to m
    for (ll i = 2; i <= m; i++) {
        ll vl = i;while (vl != 1) {
            ll d = spf[vl];
            b1[d]++;
            vl /= d;
        }
    }

    // Calculate the initial value of g
    for (auto itr = b1.begin(); itr != b1.end(); ++itr) {
        g = (g * (itr->second + 1)) % MOD;
    }
    //cout<<g<<"\n";
    long long int g1 = g;
    ll b[n + 1] = {0};

    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
        g = f(b[i]); cout<<g<<" ";
        g = g1;
      
        // // Update g by removing the effect of old factors and adding the new factors
        // for (auto itr = factors.begin(); itr != factors.end(); ++itr) {
        //     ll old_count = b1[itr->first];
        //     ll new_count = old_count + itr->second;
        //     g = g * (new_count + 1) % MOD;  // Add new count
            
        //     // Perform modular inverse and multiplication for updating g
        //     g = g * modInverse(old_count + 1, MOD) % MOD;  // Remove old count
            
            
            
       
        // }
        
        //cout << g << " ";
    }

    return 0;
}