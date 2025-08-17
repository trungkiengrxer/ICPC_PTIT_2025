/*
Cho hai số nguyên K và S. Nhiệm vụ của bạn là hãy đếm số bộ ba (X, Y, Z) khác nhau với 0 ≤ X, Y, Z ≤ K và thỏa mãn X + Y + Z = S?

Input:

Gồm 2 số nguyên K và S (2 ≤ K ≤ 2500, 0 ≤ S ≤ 3K).

Output: 

In ra số lượng bộ 3 số thỏa mãn.
*/

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long k, s;
    std::cin >> k >> s;

    long long result = 0;

    for (long long x = 0; x <= k; ++x) {
        for (long long y = 0; y <= k; ++y) {
            long long z = s - x - y;
            if (0 <= z && z <= k) ++result;
        }
    }
    std::cout << result;
}