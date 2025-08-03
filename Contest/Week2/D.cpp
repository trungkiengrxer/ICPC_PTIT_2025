/*Một nhà hàng hiện đại có các món thức ăn chuyển động theo dây chuyền. Có tất cả N vị trí chỗ ngồi, đánh dấu từ 1, 2, …, N. Vì nhà hàng rất nổi tiếng, nhiều đoàn khách tới cần phải đúng giờ và có đủ slot trống thì nhà hàng mới phục vụ.

Trong một ngày nọ, có M sự kiện diễn ra, thuộc 1 trong 2 nhóm như sau:

Một đoàn có K[i] khách đến và họ muốn ngồi liền kề nhau. Nhân viên phục vụ muốn xếp nhóm này vào một dãy liên tiếp K[i] ghế trống. Nếu có thể, nhóm được xếp vào vị trí thấp nhất trong dãy ghế. Nếu không thể, nhóm khách sẽ bị từ chối phục vụ.
Các khách ở vị trí ghế từ A[i] đến B[i] đã ăn xong và họ rời đi, những vị trí còn lại sẽ trở thành ghế trống.
Nhiệm vụ của bạn là hãy đếm số lượng đoàn khách bị từ chối phục vụ trong ngày?

Input:

Dòng đầu tiên là hai số nguyên dương N và M (1 ≤ N, M ≤ 500000).

M dòng tiếp theo, mỗi dòng mô tả một sự kiện theo thứ tự thời gian tăng dần.

Sự kiện loại 1: “A K” là có một đoàn K khách tới nhà hàng.

Sự kiện lọai 2: “L a b” là tất cả các khách từ vị trí [a, b] (a ≤ b) sẽ rời đi.

Output:

Hãy in ra một số nguyên là số lượng nhóm khách bị từ chối.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int MAX = 5e5 + 5;

std::vector<int> tree(MAX * 4); // độ dài dãy ghế dài nhất trong đoạn l, r
std::vector<int> prefix(MAX * 4); // số ghế trống liên tiếp đầu đoạn từ l
std::vector<int> suffix(MAX * 4); // số ghế trống liên tiếp cuối đoạn đến r
std::vector<int> len(MAX * 4); // Tổng số ghế
std::vector<int> lazy(MAX * 4);

void build(int idx, int l, int r) {
    lazy[idx] = 0;
    len[idx] = r - l + 1;
    if (l == r) {
        tree[idx] = prefix[idx] = suffix[idx] = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    tree[idx] = prefix[idx] = suffix[idx] = len[idx];
}

void push_down(int idx) {
    if (lazy[idx] == 0) return;
    int type = lazy[idx];

    int l = idx * 2;
    int r = idx * 2 + 1;

    if (type == 1) {
        tree[l] = prefix[l] = suffix[l] = 0;
        tree[r] = prefix[r] = suffix[r] = 0;
        lazy[l] = lazy[r] = 1;
    } else if (type == 2) {
        tree[l] = prefix[l] = suffix[l] = len[l];
        tree[r] = prefix[r] = suffix[r] = len[r];
        lazy[l] = lazy[r] = 2;
    }

    lazy[idx] = 0;
}

void update(int idx, int l, int r, int u, int v, int type) {
    if (v < l || u > r) return;
    if (u <= l && v >= r) {
        lazy[idx] = type;
        if (type == 1) {
            tree[idx] = prefix[idx] = suffix[idx] = 0;
        } else if (type == 2) {
            tree[idx] = prefix[idx] = suffix[idx] = len[idx];
        }

        return;
    }

    push_down(idx);

    int mid = (l + r) / 2;
    update(idx * 2, l, mid, u, v, type);
    update(idx * 2 + 1, mid + 1, r, u, v, type);

    prefix[idx] = prefix[idx * 2];
    if (prefix[idx] == len[idx * 2]) prefix[idx] += prefix[idx * 2 + 1];

    suffix[idx] = suffix[idx * 2 + 1];
    if (suffix[idx] == len[idx * 2 + 1]) suffix[idx] += suffix[idx * 2];

    tree[idx] = std::max({tree[idx * 2], tree[idx * 2 + 1], suffix[idx * 2] + prefix[idx * 2 + 1]});
}

int query(int idx, int l, int r, int k) {
    if (tree[idx] < k) return -1;
    if (l == r) return l;

    push_down(idx);
    int mid = (l + r) / 2;

    if (tree[idx * 2] >= k)
        return query(idx * 2, l, mid, k);
    else if (suffix[idx * 2] + prefix[idx * 2 + 1] >= k)
        return mid - suffix[idx * 2] + 1;
    else
        return query(idx * 2 + 1, mid + 1, r, k);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    build(1, 1, n);

    int result = 0;
    while (m--) {
        std::string type;
        std::cin >> type;

        if (type == "A") {
            int k;
            std::cin >> k;
            int pos = query(1, 1, n, k);
            if (pos == -1)
                ++result;
            else
                update(1, 1, n, pos, pos + k - 1, 1);
        } else {
            int u, v;
            std::cin >> u >> v;
            update(1, 1, n, u, v, 2);
        }
    }

    std::cout << result << "\n";
}