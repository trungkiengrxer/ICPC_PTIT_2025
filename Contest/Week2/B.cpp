/*
Cho dãy số A[] có N phần tử. Cho dãy số B[] ban đầu rỗng. Hãy thực hiện N thao tác sau đây:

Thao tác thứ i, hãy thêm phần tử A[i] vào cuối của dãy số B[], rồi thực hiện đảo ngược dãy số B[].

Nhiệm vụ của bạn là hãy xác định dãy số B[] sau khi thực hiện N thao tác.

Input

Dòng đầu tiên là số nguyên dương N (N ≤ 200000).

Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output

Hãy in ra dãy số B[] cuối cùng.
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::deque<int> deque;

    for (int i = 0; i < n; ++i) {
        if (i % 2 != 0)
            deque.push_front(a[i]);
        else
            deque.push_back(a[i]);
    }

    if (n % 2 == 0) std::reverse(deque.begin(), deque.end());

    while (!deque.empty()) {
        std::cout << deque.back() << " ";
        deque.pop_back();
    }
}