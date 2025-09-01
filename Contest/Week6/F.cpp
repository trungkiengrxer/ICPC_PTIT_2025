/*
Cho đồ thị vô hướng có N đỉnh và M cạnh, trong đó có tồn tại những cạnh nối 1 đỉnh với chính nó. Cạnh thứ i nối đỉnh Ai với Bi.

Bạn cần xóa bỏ một số cạnh của đồ thị, hoặc không xóa cạnh nào, sao cho đồ thị còn lại thu được vẫn phải đảm bảo tính liên thông. Khi xóa một cạnh có trọng số là C[i], nếu C[i] ≥ 0, bạn sẽ được thưởng C[i] điểm. Ngược lại, C[i] < 0, bạn bị phạt |C[i]| điểm.

Hãy tính số điểm nhiều nhất mà bạn có thể đạt được sau khi hoàn thành mục tiêu này?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

Dòng đầu tiên của mỗi test gồm số nguyên N và K (1 ≤ N ≤ 1000, 0 ≤ K ≤ 1000000).

Dòng thứ hai gồm N số nguyên B1, B2, …, BN (1 ≤ Bi ≤ 1000).

Dòng thứ hai gồm N số nguyên C1, C2, …, CN (1 ≤ Ci ≤ 1000000).

Output:

Với mỗi test, hãy in ra số lượng đồng xu tối đa bạn nhận được.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

class DSU {
   private:
    std::vector<long long> parent, size;

   public:
    DSU(long long n) {
        size.assign(n + 1, 1);
        parent.resize(n + 1);
        for (long long i = 0; i <= n; ++i) parent[i] = i;
    }

    long long find(long long u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(long long u, long long v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;
        if (size[u] < size[v]) std::swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return true;
    }
};

bool comparator(std::tuple<long long, long long, long long> a, std::tuple<long long, long long, long long> b) { return std::get<2>(a) < std::get<2>(b); }

int main() {
    long long t = 1;
    // std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::vector<std::tuple<long long, long long, long long>> posible_edges;
        long long total = 0;
        long long total_keep = 0;
        DSU dsu(n);
        for (long long i = 0; i < k; ++i) {
            long long a, b, c;
            std::cin >> a >> b >> c;
            total += c;
            if (c <= 0) {
                dsu.unite(a, b);
                total_keep += c;
            } else {
                posible_edges.push_back({a, b, c});
            }
        }

        std::sort(posible_edges.begin(), posible_edges.end(), comparator);

        for (auto &[u, v, w] : posible_edges) {
            if (dsu.unite(u, v)) {
                total_keep += w;
            }
        }

        std::cout << total - total_keep << "\n";
    }
}