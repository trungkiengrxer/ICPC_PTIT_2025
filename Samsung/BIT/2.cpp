/*
Cho dãy số A[] có N phần tử. Có Q truy vấn:

Loại 1: 1 u v K
              Tăng giá trị các phần tử A[u], A[u+1], …, A[v] lên K đơn vị

Lọai 2: 2 u
              Yêu cầu in ra giá trị phần tử A[u].

Input

Dòng đầu tiên là số nguyên N (1 <= N <= 100 000).
Dòng tiếp theo gồm N số nguyên A[i] (1 <= A[i] <= 10^9).
Tiếp theo là số lượng truy vấn Q (1 <= Q <= 100 000).
Q dòng tiếp theo, mỗi dòng gồm một loại truy vấn.
Giới hạn: 1 <= u <= v <= N, 1 <= K <= 10^9.
Output

Với mỗi truy vấn, in ra đáp án tìm được trên một dòng.
*/

#include <iostream>
#include <vector>

const long long MAX = 1e5 + 5;
std::vector<long long> bit(MAX);

void update(long long u, long long k) {
    long long idx = u;
    while (idx < MAX) {
        bit[idx] += k;
        idx += (idx & (-idx));
    }
}

long long get(long long u) {
    long long result = 0, idx = u;
    
    while (idx > 0) {
        result += bit[idx];
        idx -= (idx & (-idx));
    }

    return result;
}

int main() {
    long long n, q;
    std::cin >> n;

    std::vector<long long> a(n + 1, 0), diff(n + 1, 0);

    for (long long i = 1; i <= n; ++i) std::cin >> a[i];
    for (long long i = 1; i <= n; ++i) diff[i] = a[i] - a[i - 1];
    for (long long i = 1; i <= n; ++i) update(i, diff[i]);

    std::cin >> q;

    while (q--) {
        long long t;
        std::cin >> t;

        if (t == 1) {
            long long u, v, k;
            std::cin >> u >> v >> k;
            update(u, k);
            update(v + 1, -k);
        } else {
            long long u;
            std::cin >> u;
            std::cout << get(u) << "\n";
        }
    }
}