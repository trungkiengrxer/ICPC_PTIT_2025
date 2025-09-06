#include <iostream>
#include <vector>

using namespace std;

const long long MAX = 1e6 + 1;
vector<bool> is_primes(MAX, true);
vector<long long> primes;

void sieve() {
    is_primes[0] = is_primes[1] = false;
    for (long long i = 2; i * i <= MAX; ++i) {
        if (is_primes[i]) {
            for (long long j = i * i; j < MAX; j += i) {
                is_primes[j] = false;
            }
        }
    }

    for (int i = 2; i < MAX; ++i) {
        if (is_primes[i]) primes.push_back(i);
    }
}

long long count_divisors(long long n) {
    long long result = 1;
    for (long long p : primes) {
        if (p * p > n) break;
        long long count = 0;
        while (n % p == 0) {
            ++count;
            n /= p;
        }
        result = result * (count + 1);
    }

    if (n > 1) result = result * 2;
    return result;
}

int main() {
    sieve();
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        cout << count_divisors(n) << "\n";
    }
}