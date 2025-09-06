#include <iostream>
#include <vector>
#include <string>

const long long MAX = 101;
std::vector<std::vector<std::vector<long long>>> bit(MAX, std::vector<std::vector<long long>>(MAX, std::vector<long long>(MAX, 0)));

void update(long long x, long long y, long long z, long long k) {
    for (long long i = x; i < MAX; i += i & (-i)) {
        for (long long j = y; j < MAX; j += j & (-j)) {
            for (long long l = z; l < MAX; l += l & (-l)) {
                bit[i][j][l] += k;
            }
        }
    }
}

long long get(long long x, long long y, long long z) {
    long long result = 0;
    for (long long i = x; i > 0; i -= i & (-i)) {
        for (long long j = y; j > 0; j -= j & (-j)) {
            for (long long l = z; l > 0; l -= l & (-l)) {
                result += bit[i][j][l];
            }
        }
    }

    return result;
}

long long get_sum(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2) {
    return get(x2, y2, z2)
    - get(x1 - 1, y2, z2)
    - get(x2, y1 - 1, z2)
    - get(x2, y2, z1 - 1)
    + get(x1 - 1, y1 - 1, z2)
    + get(x1 - 1, y2, z1 - 1)
    + get(x2, y1 - 1, z1 - 1)
    - get(x1 - 1, y1 - 1, z1 - 1);
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        bit.assign(MAX, std::vector<std::vector<long long>>(MAX, std::vector<long long>(MAX, 0)));
        long long n, m;
        std::cin >> n >> m;

        std::vector<std::vector<std::vector<long long>>> a(n + 1, std::vector<std::vector<long long>>(n + 1, std::vector<long long>(n + 1, 0)));

        while (m--) {
            std::string s;
            std::cin >> s;

            if (s == "UPDATE") {
                long long x, y, z, w;
                std::cin >> x >> y >> z >> w;
                long long k = w - a[x][y][z];
                a[x][y][z] = w;
                update(x, y, z, k);
            } else {
                long long x1, y1, z1, x2, y2, z2;
                std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                std::cout << get_sum(x1, y1, z1, x2, y2, z2) << "\n";
            }
        }

    }
}