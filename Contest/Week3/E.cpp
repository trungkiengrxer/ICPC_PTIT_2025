/*
Alice và Bob đang chơi một trò chơi như sau:

Có 2 đống sỏi, có lần lượt X và Y viên sỏi. Lần lượt mỗi người chơi sẽ lấy đi 2*A viên sỏi từ một đống nào đó, rồi trả lại A viên sỏi cho đống còn lại. Ai không thực hiện được bước đi sẽ là người thua cuộc.

2 bạn chơi lần lượt, Alice là người đi trước. Các bạn hãy xác định xem ai sẽ là người chiến thắng nếu như cả hai đều có chiến thuật tối ưu?

Input:

Dữ liệu đầu vào gồm hai số nguyên X và Y (0 ≤ X, Y ≤ 1018).

Output:

Với mỗi test, in ra “Alice” hoặc “Bob” là người chiến thắng.
*/

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long x, y;
    std::cin >> x >> y;

    if (std::abs(x - y) <= 1)
        std::cout << "Bob";
    else
        std::cout << "Alice";
}