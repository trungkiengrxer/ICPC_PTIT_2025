/*
Trên mặt phẳng Oxy, cho N điểm P[]. Tọa độ của giữa 2 điểm (x1, y1) và (x2, y2) được tính theo khoảng cách Euclidean: sqrt((x1 – x2)2 + (y1 – y2)2).

Với mỗi điểm, bạn hãy tìm chỉ số ID của điểm xa nhất với nó.

Input

Dòng đầu tiên là số nguyên dương N (2 ≤ N ≤ 100).

N dòng tiếp theo, mỗi dòng gồm 2 số nguyên xi, yi mô tả tọa độ của một điểm. Input đảm bảo tọa độ các điểm là riêng biệt. Có tọa độ có giá trị tuyệt đối không vượt quá 1000.

Output

In ra N dòng, dòng thứ i là ID của điểm cách xa điểm Pi nhất. Nếu có nhiều đáp án, hãy in ra điểm có ID nhỏ hơn.
*/

#include <cmath>
#include <iostream>
#include <vector>

double get_distance(std::pair<int, int> &a, std::pair<int, int> &b) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return std::sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);
    std::vector<int> result(n);
    for (int i = 0; i < n; ++i) std::cin >> points[i].first >> points[i].second;

    for (int i = 0; i < n; ++i) {
        double max_distance = -1e9;
        for (int j = 0; j < n; ++j) {
            double distance = get_distance(points[i], points[j]);
            if (distance > max_distance) {
                result[i] = j + 1;
                max_distance = distance;
            }
        }
    }

    for (int i = 0; i < n; ++i) std::cout << result[i] << "\n";
}