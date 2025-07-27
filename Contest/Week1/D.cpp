/*
Cho dãy số A[] có N phần tử. Mỗi phần tử sẽ cần được gán cho một màu sắc nào đó sao cho tính chất sau luôn được thỏa mãn:

Với 2 phần tử A[i] và A[j] (i < j) được tô cùng một màu thì bắt buộc A[i] < A[j].

Nhiệm vụ của bạn là hãy xác định xem cần sử dụng ít nhất bao nhiêu màu để có thể tô màu được dãy số đã cho.

Input:

Dòng đầu tiên chứa số nguyên N (1 ≤ N ≤ 100000).

Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output: 

In ra một số nguyên là số lượng màu sắc cần dùng ít nhất.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Đảo dấu để chuyển LDS thành LIS
    for (int &x : a) x = -x;

    // Tìm LIS trên dãy bị đảo dấu => chính là LDS ban đầu
    vector<int> lis;
    for (int x : a) {
        auto it = upper_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    cout << lis.size() << '\n'; // Số màu tối thiểu
}