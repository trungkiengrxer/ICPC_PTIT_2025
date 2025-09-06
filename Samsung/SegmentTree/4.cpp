#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const long long MAX = 2e5 + 5;

vector<long long> a(MAX);
vector<long long> tree1(MAX * 4);
vector<long long> tree2(MAX * 4);

pair<int, int> merge(int l1, int r1, int l2, int r2) {
    vector<int> temp = {l1, r1, l2, r2};
    sort(temp.rbegin(), temp.rend());
    return {temp[0], temp[1]};
}

void build(long long idx, long long l, long long r) {
    if (l == r) {
        tree1[idx] = a[l];
        tree2[idx] = -1e9;
        return;
    }

    long long mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    pair<int, int> result = merge(tree1[2 * idx], tree1[2 * idx + 1], tree2[2 * idx], tree2[2 * idx + 1]);
    tree1[idx] = result.first;
    tree2[idx] = result.second;
}

void update(long long idx, long long l, long long r, long long u, long long val) {
    if (l == r) {
        tree1[idx] = val;
        tree2[idx] = -1e9;
        return;
    }

    long long mid = (l + r) / 2;
    if (u <= mid) {
        update(2 * idx, l, mid, u, val);
    } else {
        update(2 * idx + 1, mid + 1, r, u, val);
    }

    pair<int, int> result = merge(tree1[2 * idx], tree1[2 * idx + 1], tree2[2 * idx], tree2[2 * idx + 1]);
    tree1[idx] = result.first;
    tree2[idx] = result.second;
}

pair<int, int> query(long long idx, long long l, long long r, long long u, long long v) {
    if (r < u || l > v) return {-1e9, -1e9};
    if (u <= l && r <= v) return {tree1[idx], tree2[idx]};

    long long mid = (l + r) / 2;
    pair<int, int> p1 = query(idx * 2, l, mid, u, v);
    pair<int, int> p2 = query(idx * 2 + 1, mid + 1, r, u, v);

    return merge(p1.first, p1.second, p2.first, p2.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, q;
    cin >> n >> q;
    for (long long i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    while (q--) {
        char t;
        cin >> t;
        if (t == 'U') {
            long long u, val;
            cin >> u >> val;
            update(1, 1, n, u, val);
        } else {
            long long u, v;
            cin >> u >> v;
            cout << query(1, 1, n, u, v).first + query(1, 1, n, u, v).second << "\n";
        }
    }
}