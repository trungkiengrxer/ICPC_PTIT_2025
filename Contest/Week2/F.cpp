/*
Cho N chai soda. Chai thứ i hiện chứa A[i] đơn vị soda và có dung tích tối đa là B[i] (A[i] ≤ B[i]). Cần thực hiện thao tác đổ soda giữa các chai để dồn toàn bộ lượng soda hiện có vào số lượng chai ít nhất có thể. Mục tiêu cụ thể là:

Sử dụng số lượng chai ít nhất có thể (gọi là K chai).
Trong số các cách để đạt được K chai, hãy chọn cách tốn ít thời gian nhất (gọi là T).
Biết rằng việc đổ X đơn vị soda từ một chai sang chai khác mất X giây.
Lưu ý:

Lượng soda trong mỗi chai sau khi đổ không được vượt quá dung tích B[i] của chai đó, và tổng lượng soda ban đầu phải được bảo toàn.

Nhiệm vụ của bạn là hãy xác định giá trị K và T.

Input:

Dòng đầu tiên chứa số nguyên dương N (1 ≤ N ≤ 100) - là số lượng chai.

Dòng thứ hai gồm N số nguyên dương A[i] (1 ≤ A[i] ≤ 100), trong đó A[i] là lượng soda còn lại trong chai thứ i.

Dòng thứ ba chứa N số nguyên dương B[i] (1 ≤ B[i] ≤ 100), trong đó B[i] là dung tích của chai thứ i.

Output:

In ra hai số nguyên K và T, trong đó K là số lượng chai tối thiểu có thể chứa tất cả soda và T là thời gian tối thiểu để đổ soda vào K chai đó.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool comparator(std::pair<long long, long long> a, std::pair<long long, long long> b) { return a.second > b.second; }

int main() {
    long long n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> a(n);

    long long total = 0;
    for (long long i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        total += a[i].first;
    }

    for (long long i = 0; i < n; ++i) std::cin >> a[i].second;

    std::sort(a.begin(), a.end(), comparator);

    long long k = 0;
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += a[i].second;
        ++k;
        if (sum >= total) break;
    }

    std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(total + 1, -1e9));

    //dp[j][s]: dung tích lớn nhất khi chọn j chai và tổng soda là s
    dp[0][0] = 0;
    for (long long i = 0; i < n; ++i) {
        auto [first, second] = a[i];
        for (long long j = k - 1; j >= 0; --j) {
            for (long long s = 0; s <= total; ++s) {
                if (dp[j][s] < 0) continue;
                long long x = std::min(s + second, total);
                dp[j + 1][x] = std::max(dp[j + 1][x], dp[j][s] + first);
            }
        }
    }

    long long t = total - dp[k][total];

    std::cout << k << " " << t;
}