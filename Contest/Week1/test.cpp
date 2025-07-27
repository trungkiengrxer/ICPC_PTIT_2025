#include <iostream>

int main() {
    long long n;
    while (std::cin >> n) {
        long long count = 0;
        for (long long i = 1; i <= n; ++i) {
            if (n % i == 0) ++count;
        }
        std::cout << count << "\n";
    }
}