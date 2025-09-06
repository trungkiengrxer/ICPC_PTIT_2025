#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <tuple>
#include <list>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Tổ hợp modulo, không dp
const long long MOD = 1e9 + 7;
const long long MAX = 200000;
long long fact[MAX + 1], inv_fact[MAX + 1];

long long my_pow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = ((long long)result * a) % mod;
        a = ((long long)a * a) % mod;
        b /= 2;
    }
    return result;
}

void factorial() {
    fact[0] = 1;
    for (long long i = 1; i <= MAX; ++i) {
        fact[i] = ((long long)fact[i - 1] * i) % MOD;
    }
}

void inverse_factorial() {
    inv_fact[MAX] = my_pow(fact[MAX], MOD - 2, MOD);
    for (long long i = MAX; i >= 1; --i) {
        inv_fact[i - 1] = ((long long)inv_fact[i] * (i)) % MOD;
    }
}

long long combination(long long n, long long k) {
    return ((long long)fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD) % MOD;
}
// ===================================================================================

// Sàng nguyên tố
vector<int> primes;
void sieve(int n){
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < n; ++i)
        if(is_prime[i])
            for(int j = i * i; j < n; j += i)
                is_prime[j] = false;

    for(int i = 2; i < n; ++i)
        if(is_prime[i]) primes.push_back(i);
}

