/*
Cho N stick, mỗi stick có độ dài bằng A[i]. Nhiệm vụ của bạn là hãy đếm số lượng cách chọn 3 chiếc stick để có thể tạo thành một tam giác có độ dài các cạnh khác nhau?

Nói cách khác, bạn cần tìm số lượng bộ ba (i, j, k) (1≤i<j<k≤N) thỏa mãn:

A[i], A[j], A[k] đôi một khác nhau.
A[i], A[j], A[k] tạo thành một tam giác
Input:

Dòng đầu tiên là số nguyên dương N (1 ≤ N ≤ 100).

Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 10^9).

Output:

In ra một số nguyên là số cách chọn bộ ba stick để tạo thành tam giác thỏa mãn yêu cầu.
*/

#include <cmath>
#include <iostream>
#include <vector>

bool is_trangle(long long a, long long b, long long c) { return a + b > c && a + c > b && b + c > a; }

int main() {
    long long n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i];

    long long count = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = i + 1; j < n; ++j) {
            for (long long k = j + 1; k < n; ++k) {
                if (a[i] != a[j] && a[j] != a[k] && a[i] != a[k]) {
                    if (is_trangle(a[i], a[j], a[k])) {
                        ++count;
                    }
                }
            }
        }
    }

    std::cout << count << "\n";
}