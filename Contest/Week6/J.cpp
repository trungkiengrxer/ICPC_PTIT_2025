/*
Cho A đồng xu vàng, B đồng xu bạc và C đồng xu bằng đồng ở trong hộp. Khi chưa có đủ 100 đồng xu nào đó cùng màu, ta thực hiện các thao tác sau:

Lấy ngẫu nhiên ra một đồng xu khỏi hộp (xác suất lấy được mỗi đồng xu là bằng nhau) rồi bỏ vào trong hộp 2 đồng xu cùng loại. Hỏi số bước trung bình để có đủ được 100 đồng xu cùng loại bằng bao nhiêu?

Input

Chứa 3 số nguyên A, B, C (0 ≤ A, B, C ≤ 99, A+ B + C > 0).
Output

In ra một số thực là giá trị kì vọng số thao tác thực hiện với độ chính xác 6 chữ số sau dấu phảy.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    double min = std::min({a, b, c});

    double t1 = 1.0 * (100 - a) * a / (a + b + c);
    double t2 = 1.0 * (100 - b) * b / (a + b + c);
    double t3 = 1.0 * (100 - c) * c / (a + b + c);

    std::cout << std::fixed << std::setprecision(6) << t1 + t2 + t3;
}