/*
Với hai số tự nhiên N và K (K < N), số tổ hợp chập K của N phần tử được ký hiệu là C(K,N).

Bài toán đặt ra là hãy đếm số ước số của C(K,N).

Input

Có rất nhiều test (bạn cần đọc hết các dòng trong dữ liệu vào).

Mỗi test ghi trên một dòng hai số N và K (0 ≤ K ≤ N < 500).

Output

Với mỗi test, ghi kết quả trên một dòng.

Dữ liệu vào đảm bảo kết quả không vượt quá kiểu số nguyên 64 bít..
*/

#include <iostream>
#include <vector>
#include <cmath>

const unsigned long long MAX = 500 + 1;
std::vector<bool> is_primes(MAX, true);
std::vector<unsigned long long> primes;

void sieve() {
    is_primes[0] = is_primes[1] = false;

    for (unsigned long long i = 2; i * i < MAX; ++i) {
        if (is_primes[i]) {
            for (unsigned long long j = i * i; j < MAX; j += i) {
                is_primes[j] = false;
            } 
        }
    }

    for (unsigned long long i = 2; i < MAX; ++i) {
        if (is_primes[i]) primes.push_back(i);
    }
}

unsigned long long get_exp(unsigned long long n, unsigned long long p) {
    unsigned long long l = log10(n) / log10(p);
    unsigned long long result = 0;

    // Cách 1: duyệt từ 1 đến l, nhưng sai do đâu đó nên đặt giới hạn là 8
    // for (unsigned long long i = 1; i <= 8; ++i) {
    //     result += std::floor((n / std::pow(p, i)));
    // }
    
    // Cách 2
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

    sieve();

    unsigned long long n, k;
    while (std::cin >> n >> k) {

        if (n == k || n == 0 || k == 0) {
            std::cout << 1 << "\n";
            continue;
        }

        if (n < k) {
            std::cout << 0 << "\n";
            continue;
        }

        unsigned long long result = 1;

        for (unsigned long long p : primes) {
            if (p > n) break;

            unsigned long long exp1 = get_exp(n, p);
            unsigned long long exp2 = get_exp(k, p);
            unsigned long long exp3 = get_exp(n - k, p);

            unsigned long long exp = exp1 - (exp2 + exp3);
            if (exp > 0) result *= (exp + 1);
        }

        std::cout << result << "\n";
    }
}