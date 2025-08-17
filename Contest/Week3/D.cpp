/*
Cho tập N điểm trong không gian hai chiều Oxy. Nhiệm vụ của bạn là xóa đi một điểm sao cho khoảng cách lớn nhất giữa hai điểm bất kì của các điểm còn lại là nhỏ nhất. Khoảng cách giữa hai điểm A và B được tính theo công thức Manhattan:

dist(A, B) = |xA – xB| + |yA – yB|

Hãy in ra giá trị khoảng cách lớn nhất nhỏ nhất có thể tìm được.

Input:

Dòng đầu nhập số nguyên N là số lượng các điểm (3 ≤ N ≤ 100000).

N dòng tiếp theo, mỗi dòng nhập hai số nguyên Xi và Yi mô tả tọa độ của một điểm.

(0 ≤ Xi, Yi ≤ 10^9).

Output:
Hãy in ra đáp án trên một dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> a(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;

    std::vector<std::pair<long long, long long>> v1(n), v2(n);

    long long idx = 0;
    for (const auto &[x, y] : a) {
        v1[idx] = {x + y, idx};
        v2[idx] = {x - y, idx};
        ++idx;
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::vector<long long> temp;

    temp.push_back(v1.front().second);
    temp.push_back(v1.back().second);
    temp.push_back(v2.back().second);
    temp.push_back(v2.front().second);

    long long result = 1e18;
    for (long long index : temp) {
        long long min1 = 1e18, max1 = -1e18;
        long long min2 = 1e18, max2 = -1e18;

        for (long long i = 0; i < n; ++i) {
            if (index == i) continue;

            long long c = a[i].first + a[i].second;
            min1 = std::min(min1, c);
            max1 = std::max(max1, c);

            long long d = a[i].first - a[i].second;
            min2 = std::min(min2, d);
            max2 = std::max(max2, d);
        }
        result = std::min(result, std::max(max1 - min1, max2 - min2));
    }

    std::cout << result;
}