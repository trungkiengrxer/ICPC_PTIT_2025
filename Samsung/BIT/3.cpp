/*
Cho dãy số A[] có N phần tử. Hãy đếm số bộ ba các số thứ tự ngược, tức là A[i] > A[j] > A[k] với i < j < k.

Input

Dòng đầu tiên là số lượng bộ test (<= 20).
Mỗi test gồm một số nguyên dương N (N <= 10^5)
Dòng tiếp theo gồm N số nguyên dương A[i] (1 <= A[i] <= N).
Output

Với mỗi test, in ra đáp án tìm được trên một dòng.
*/

#include <iostream>
#include <vector>

const long long MAX = 1e5 + 7;
std::vector<long long> bit1(MAX);
std::vector<long long> bit2(MAX);
std::vector<long long> f(MAX, 0);

void update(std::vector<long long> &bit, long long u, long long k) {
    long long idx = u;
    while (idx < MAX) {
        bit[idx] += k;
        idx += (idx & (-idx));
    }
}

long long get(std::vector<long long> &bit, long long u) {
    long long idx = u, result = 0;
    while (idx > 0) {
        result += bit[idx];
        idx -= (idx & (-idx));
    }

    return result;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        bit1.assign(MAX, 0);
        bit2.assign(MAX, 0);
        f.assign(MAX, 0);
        long long n, sum = 0;
        std::cin >> n;

        std::vector<long long> a(n + 1);
        for (long long i = 1; i <= n; ++i) std::cin >> a[i];

        for (long long j = n; j >= 1; --j) {
            f[j] = get(bit1, a[j] - 1);
            update(bit1, a[j], 1);
        }

        for (long long i = n; i >= 1; --i) {
            sum += get(bit2, a[i] - 1);

            update(bit2, a[i], f[i]);
        }

        std::cout << sum << "\n";
    }
}