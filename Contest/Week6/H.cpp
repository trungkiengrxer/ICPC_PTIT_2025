/*
Cho N điểm phân biệt trên mặt phẳng Oxy. Khoảng cách giữa 2 điểm A và B được tính theo công thức min(|xA – xB|, |yA – yB|).

Hãy tìm khoảng cách lớn nhất giữa 2 điểm trong N điểm đã cho?

Input

Dòng đầu tiên là số nguyên dương N (2 ≤ N ≤ 200000).

N dòng tiếp theo, mỗi dòng gồm 2 số nguyên mô tả tọa độ của một điểm. Tọa độ các điểm là số nguyên không âm và không vượt quá 109.

Output

In ra một số nguyên là giá trị khoảng cách lớn nhất giữa 2 điểm.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::vector<std::pair<long long, long long>> a;

bool is_ok(long long k, long long n) {
    std::multiset<long long> set;
    long long index = 0;
    for (long long r = 0; r < n; ++r) {
        long long xr = a[r].first;
        long long yr = a[r].second;

        while (index < r && a[index].first <= xr - k) {
            set.insert(a[index].second);
            ++index;
        }

        if (set.empty()) continue;

        auto it1 = set.lower_bound(yr + k);
        if (it1 != set.end()) return true;

        auto it2 = set.upper_bound(yr - k);
        if (it2 != set.begin()) return true;
    }
    return false;
}

int main() {
    long long n;
    std::cin >> n;

    a.resize(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;

    std::sort(a.begin(), a.end());

    long long left = 0, right = 1e9;
    while (left < right) {
        long long mid = (left + right) / 2 + 1;
        if (is_ok(mid, n))
            left = mid;
        else
            right = mid - 1;
    }

    std::cout << left;
}