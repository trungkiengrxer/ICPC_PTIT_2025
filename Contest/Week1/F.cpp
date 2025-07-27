/*
Cho hai số a và b trong đó a≤1012, b≤10250. Nhiệm vụ của bạn là tìm ước số chung lớn nhất của hai số a, b.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp đưa các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào số a; dòng tiếp theo đưa vào số b.
Các số T, a, b thỏa mãn ràng buộc: 1≤T≤100; 1≤a≤1012; 1≤b≤10250;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <string>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long mod(std::string a, long long b) {
    long long result = 0;
    for (char digit : a) {
        result = (result * 10 + (digit - '0')) % b;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long t;
    std::cin >> t;

    while (t--) {
        long long a;
        std::string b;

        std::cin >> a >> b;
        long long x = mod(b, a);
        std::cout << gcd(a, x) << "\n";
    }
}