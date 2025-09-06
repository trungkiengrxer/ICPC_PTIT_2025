#include <iostream>
#include <unordered_map>
#include <vector>

long long get_exp(long long n, long long p) {
    long long result = 0;
    while (n > 0) {
        n /= p;
        result += n;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k, m = 1e18;
        std::cin >> n >> k;

        std::unordered_map<long long, long long> map;

        for (long long p = 2; p * p <= k; ++p) {
            while (k % p == 0) {
                ++map[p];
                k /= p;
            }
        }

        if (k > 1) ++map[k];

        for (auto &[first, second] : map) {
            m = std::min(m, get_exp(n, first) / second);
        }

        std::cout << m << "\n";
    }
}