#include <iostream>
#include <map>
#include <vector>

std::vector<bool> is_prime(1e6 + 1, true);
std::vector<long long> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i < 1e6 + 1; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j < 1e6 + 1; j += i) is_prime[j] = false;
        }
    }
    for (long long i = 2; i < 1e6 + 1; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

int main() {
    sieve();

    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::map<long long, long long> map;

        for (long long p : primes) {
            if (p * p > n) break;
            while (n % p == 0) {
                ++map[p];
                n /= p;
            }
        }

        if (n > 1) ++map[n];

        for (auto &[first, second] : map) std::cout << first << " " << second << "\n";
    }
}