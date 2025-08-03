/*
Cho dãy số A[] có N phần tử. Hãy xác định xem có tồn tại một đa giác (không nhất thiết phải lồi) có độ dài các cạnh tương ứng là tập hợp A[] hay không?

Gợi ý điều kiện cần và đủ: Một đa giác có N cạnh có tính chất: độ dài của cạnh dài nhất phải nhỏ hơn tổng của N-1 cạnh còn lại.

Input:

Dòng đầu tiên là số lượng cạnh N (1 ≤ N ≤ 100).

Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 100).

Output: 

In ra “Yes” nếu tồn tại đa giác, in “No” trong trường hợp ngược lại.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i];

    std::sort(a.begin(), a.end());
    long long sum = 0;
    for (long long i = 0; i < n - 1; ++i) sum += a[i];

    if (sum > a[n - 1]) std::cout << "Yes";
    else std::cout << "No";
}