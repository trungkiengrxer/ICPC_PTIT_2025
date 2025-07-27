/*
Cho dãy số A[] gồm N số nguyên A[1], A[2],...,A[N]. Mỗi số nguyên có giá trị từ 0 đến M−1 với M là một số cho trước.

Trong một thao tác, bạn có thể chọn một số nguyên K và K chỉ số i1,i2,...,iK (với 1 ≤ i1 < i2 <...< iK ≤ N). Sau đó, với mỗi chỉ số ix đã chọn, bạn thay đổi giá trị A[ix] thành (A[ix]+1) (mod M).

Tìm số thao tác tối thiểu để biến dãy số A[] thành một dãy số không giảm (tức là A[1] ≤ A[2] ≤ ... ≤ A[N]).

Input:

Dòng đầu tiên gồm hai số nguyên N và N (1 ≤ N, M ≤ 300000).

Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] < M).

Output:

In ra một số nguyên là số thao tác tối thiểu cần được thực hiện. Nếu không cần thao tác nào, hãy in ra 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> a;

bool is_ok(int k) {
    // Xây thử mảng mới sao cho không giảm
    std::vector<int> b = a;
    if (b[0] > (b[0] + k) % m) b[0] = 0;
    for (int i = 1; i < n; ++i) {
        int x1 = b[i];
        int x2 = (b[i] + k) % m;
        if (x1 <= x2) {
            if (x2 < b[i - 1]) {
                return false;
            } else b[i] = std::max(b[i - 1], x1);
        } else {
            if (x1 <= b[i - 1] || x2 >= b[i - 1]) b[i] = b[i - 1];
        }
    }

    return true;
}

int main() {
    int result = 0;
    std::cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int left = 0, right = m;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_ok(mid)) {
            result = mid;
            right = mid - 1;
        } else left = mid + 1;
    }

    std::cout << result;
}