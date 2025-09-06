/*
Cho dãy số A[] có N phần tử. Có Q truy vấn:

Loại 1: 1 u K
Tăng giá trị phần tử A[u] lên K đơn vị

Lọai 2: 2 u v
Yêu cầu in ra tổng A[u] + A[u+1] + … + A[v].

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

using namespace std;

const long long MAX = 1e5 + 5;

vector<long long> bit(MAX);

void update(long long u, long long v) {
    long long idx = u;
    while (idx < MAX) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

long long get(long long u) {
    long long idx = u, result = 0;
    while (idx > 0) {
        result += bit[idx];
        idx -= (idx & (-idx));
    }
    return result;
}

int main() {
    long long n, q;
    cin >> n;

    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; ++i) cin >> a[i];

    for (long long i = 1; i <= n; ++i) update(i, a[i]);

    cin >> q;

    while (q--) {
        long long t;
        cin >> t;

        if (t == 1) {
            long long u, k;
            cin >> u >> k;
            update(u, k);
        } else {
            long long u, v;
            cin >> u >> v;
            cout << get(v) - get(u - 1) << "\n";
        }
    }
}