/*
Một bộ ba số (a,b,c) được gọi là bộ ba số Pytago nếu a2 = b2 + c2.

Người ta mở rộng thêm khái niệm mới, bộ ba số được gọi là “siêu Pytago” nếu 2*a2 = b2 + c2. Trong đó (a,b,c) từng đôi một khác nhau.

Bài toán đặt ra là cho số nguyên dương a, hãy kiểm tra xem liệu có tồn tại các giá trị b,c để tạo ra bộ ba số “siêu Pytago” hay không. Chú ý: 1 ≤ a, b, c ≤ 105

Input

Chỉ có một số nguyên dương a (1 ≤ a ≤ 10^5)

Output

Ghi ra YES hoặc NO tuỳ thuộc kết quả kiểm tra.
*/

#include <iostream>
#include <vector>

int main() {
    long long a;
    std::cin >> a;

    long long left = 1, right = 1e5;
    bool is_ok = false;

    while (left < right) {
        long long sum = left * left + right * right;

        if (sum == 2 * a * a) {
            if (left != a && right != a) {
                is_ok = true;
                break;
            } else {
                ++left;
                --right;
            }

        } else if (sum < 2 * a * a) {
            ++left;
        } else if (sum > 2 * a * a)
            --right;
    }

    if (is_ok)
        std::cout << "YES";
    else
        std::cout << "NO";
}