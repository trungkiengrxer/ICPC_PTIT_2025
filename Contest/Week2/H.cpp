/*
Lớp học Cấu trúc dữ liệu & giải thuật có N sinh viên, trong đó có một số nhóm sinh viên chơi thân với nhau. Nếu X và Y là bạn, Y và Z là bạn, theo tính chất bắc cầu, X và Z cũng là bạn.

Để tránh việc trao đổi bài, các thầy cô đã sắp xếp phòng thi cho các bạn sinh viên sao cho không có bất kì 2 sinh viên nào là bạn của nhau ở cùng một phòng. Các bạn hãy thử tính xem các thầy cô cần sử dụng ít nhất bao nhiêu phòng thi?

Input:

Dòng đầu tiên chứa hai số nguyên N và M (N, M ≤ 200000).

M dòng tiếp theo, mỗi dòng gồm 2 số nguyên A[i] và B[i], cho biết A[i] và B[i] là bạn của nhau (A[i] khác B[i]).

Output:

In ra một số nguyên duy nhất là số phòng thi tìm được.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class DSU {
   private:
    int max_size = 0;
    std::vector<int> size, parent;

   public:
    DSU(int n) {
        size.assign(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;
        if (size[u] < size[v]) std::swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    DSU dsu(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        dsu.unite(u, v);
    }

    std::unordered_map<int, int> map;
    for (int u = 1; u <= n; ++u) {
        ++map[dsu.find(u)];
    }

    int result = 0;
    for (const auto [u, freq] : map) {
        result = std::max(result, freq);
    }

    std::cout << result;
}