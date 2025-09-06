#include <iostream>
#include <vector>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool is_valid(std::vector<long long> &b) {
    for (long long num : b) {
        if (num != 1) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, m;
    std::cin >> n >> m;

    long long k = m;

    std::vector<long long> result;
    std::vector<long long> a(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i];

    while (m--) {
        std::vector<long long> temp = a;
        std::vector<long long> b(n);

        for (long long i = 0; i < n; ++i) std::cin >> b[i];

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < n; ++j) {
                long long gcd_num = gcd(temp[i], b[j]);
                temp[i] /= gcd_num;
                b[j] /= gcd_num;
            }
        }

        if (is_valid(b)) result.push_back(k - m);
    }

    std::cout << result.size() << "\n";
    for (long long r : result) std::cout << r << " ";
}