
/*
Cho dãy số A[] có N phần tử. Có 2 loại truy vấn như sau:

1 u val: Cập nhật A[u] = val

2 u v X: Hãy in ra giá trị phần tử nhỏ nhất trong đoạn [u, v] mà có giá trị lớn hơn X? Nếu không tồn tại số nào, hãy in ra -1.

Input:

Dòng đầu tiên gồm 2 số nguyên, số lượng phần tử N và số lượng truy vấn M (N, M ≤ 100000).

Dòng tiếp theo gồm N số nguyên mô tả dãy số A[i] (0 ≤ A[i] ≤ 109).

M dòng tiếp, mỗi dòng gồm 1 truy vấn.

Output:

Với mỗi truy vấn loại 2, hãy in ra đáp án tìm được trên một dòng.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

long long MAX = 1e5 + 5;
std::vector<long long> a(MAX);
std::vector<std::multiset<long long>> tree;

void build(long long idx, long long l, long long r) {
    if (l == r) {
        tree[idx].insert(a[l]);
        return;
    }

    long long mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    auto &left = tree[idx * 2];
    auto &right = tree[idx * 2 + 1];

    if (left.size() < right.size()) {
        tree[idx] = right;
        tree[idx].insert(left.begin(), left.end());
    } else {
        tree[idx] = left;
        tree[idx].insert(right.begin(), right.end());
    }
}

void update(long long idx, long long l, long long r, long long u, long long old, long long val) {
    if (!tree[idx].empty()) {
        auto it = tree[idx].find(old);
        if (it != tree[idx].end()) tree[idx].erase(it);
    }
    tree[idx].insert(val);

    if (l == r) return;

    long long mid = (l + r) / 2;
    if (u <= mid)
        update(idx * 2, l, mid, u, old, val);
    else
        update(idx * 2 + 1, mid + 1, r, u, old, val);
}

long long query(long long idx, long long l, long long r, long long u, long long v, long long x) {
    if (r < u || l > v) return 1e18;
    if (u <= l && v >= r) {
        if (tree[idx].empty()) return 1e18;
        auto it = tree[idx].upper_bound(x);
        if (it == tree[idx].end())
            return 1e18;
        else
            return *it;
    }
    long long mid = (l + r) / 2;
    long long a1 = query(idx * 2, l, mid, u, v, x);
    long long a2 = query(idx * 2 + 1, mid + 1, r, u, v, x);
    return std::min(a1, a2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, m;
    std::cin >> n >> m;

    tree.resize(4 * n + 5);
    for (long long i = 1; i <= n; ++i) std::cin >> a[i];
    build(1, 1, n);

    while (m--) {
        long long t;
        std::cin >> t;

        if (t == 1) {
            long long u, val;
            std::cin >> u >> val;
            if (a[u] == val) continue;
            update(1, 1, n, u, a[u], val);
            a[u] = val;
        } else {
            long long u, v, x;
            std::cin >> u >> v >> x;
            long long result = query(1, 1, n, u, v, x);
            if (result == 1e18)
                std::cout << "-1\n";
            else
                std::cout << result << "\n";
        }
    }
}