#include <iostream>
#include <vector>

const long long MAX = 1e5 + 1;
std::vector<long long> bit(MAX);

void update(long long u, long long v) {
    long long idx = u;
    while (idx < MAX) {
        bit[idx] += v;
        idx += idx & (-idx);
    }
}

long long get(long long u) {
    long long idx = u, result = 0;
    while (idx > 0) {
        result += bit[idx];
        idx -= idx & (-idx);
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, q;
    std::cin >> n;

    std::vector<long long> a(n + 1);
    for (long long i = 1; i <= n; ++i) std::cin >> a[i];
    for (long long i = 1; i <= n; ++i) update(i, a[i]);

    std::cin >> q;
    while (q--) {
        long long t;
        std::cin >> t;

        if (t == 1) {
            long long u, k;
            std::cin >> u >> k;
            update(u, k);
        } else {
            long long u, v;
            std::cin >> u >> v;
            std::cout << get(v) - get(u - 1) << "\n";
        }
    }
}