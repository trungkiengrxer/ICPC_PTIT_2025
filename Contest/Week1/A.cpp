/*
Cho N điểm trên mặt phẳng Oxy. Input đảm bảo không có 2 điểm nào có cùng tọa độ. Hãy đếm số cách chọn ra 3 điểm để tạo thành một tam giác có diện tích lớn hơn 0?

Input:

Dòng đầu tiên chứa số nguyên N (3 ≤ N ≤ 300).

N dòng tiếp theo, mỗi dòng gồm 2 số nguyên X[i] và Y[i] mô tả tọa độ của một điểm (-109 ≤ X[i], Y[i] ≤ 109).

Output:

In ra một số nguyên là số lượng tam giác tìm được.
*/

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    
}