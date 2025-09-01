/*
Cho N số nguyên A[1], A[2], …, A[N] thỏa mãn A[1] x A[2] x … x A[N] = P với số P cho trước.

Nhiệm vụ của bạn là hãy tính giá trị lớn nhất có thể của GCD(A[1], A[2], …, A[N]).

Input:

Input gồm hai số nguyên dương N và P (1 ≤ N, P ≤ 10^12).

Output:

In ra một số nguyên là đáp án tìm được.
*/

#include <cmath>
#include <iostream>
#include <map>
#include <vector>

int main() {
    long long n, p;
    std::cin >> n >> p;

    std::map<long long, long long> factors;

    for (long long i = 2; i * i <= p; ++i) {
        while (p % i == 0) {
            ++factors[i];
            p /= i;
        }
    }
    if (p > 1) ++factors[p];

    long long result = 1;
    for (auto &[factor, exp] : factors) {
        long long k = exp / n;
        result *= std::pow(factor, k);
    }
    std::cout << result;
}
