/*
Cho hai số nguyên A và B. Bạn có thể thực hiện một chuỗi các phép tính: trong phép tính đầu tiên, chọn một số và tăng nó lên 1; trong phép tính thứ hai, chọn một số và tăng nó lên 2, v.v. Bạn được phép tự chọn số lượng các phép tính này.

Ví dụ, nếu A = 1 và B = 3, bạn có thể thực hiện chuỗi ba phép tính sau:

1. Cộng 1 vào A, khi đó A = 2 và B = 3

2. Cộng 2 vào B, khi đó A = 2 và B = 5

3. Cộng 3 vào A, khi đó A = 5 và B = 5

Hãy tính số phép tính tối thiểu cần thiết để làm cho A và B bằng nhau.

Input:

Dòng đầu tiên chứa số lượng bộ test T (T ≤ 100).

Mỗi test gồm hai số nguyên A và B (1 ≤ A, B ≤ 109).

Output:

Với mỗi test, hãy in ra một số nguyên là số lượng phép tính tối thiểu để biến đổi cho A và B bằng nhau.
*/

#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    long long t;
    std::cin >> t;

    while (t--) {
        long long a, b, k = 0;
        std::cin >> a >> b;

        long long d = std::abs(a - b);

        while (true) {
            long long s = k * (k + 1) / 2;
            if (s >= d && (s - d) % 2 == 0) break;
            ++k;
        }

        std::cout << k << "\n";
    }
}