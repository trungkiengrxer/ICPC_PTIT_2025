#include <iostream>
#include <vector>

using namespace std;
const long long MAX = 2e5 + 5;

vector<long long> a(MAX);
vector<long long> tree(MAX * 4);

int merge(int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;

    if (a[i] <= a[j])
        return i;
    else
        return j;
}

void build(long long idx, long long l, long long r) {
    if (l == r) {
        tree[idx] = l;
        return;
    }

    long long mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
}

void update(long long idx, long long l, long long r, long long u, long long val) {
    if (l == r) {
        a[u] = val;
        return;
    }

    long long mid = (l + r) / 2;
    if (u <= mid) {
        update(2 * idx, l, mid, u, val);
    } else {
        update(2 * idx + 1, mid + 1, r, u, val);
    }
    tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
}

long long query(long long idx, long long l, long long r, long long u, long long v) {
    if (r < u || l > v) return -1;
    if (u <= l && r <= v) return tree[idx];

    long long mid = (l + r) / 2;
    long long p1 = query(idx * 2, l, mid, u, v);
    long long p2 = query(idx * 2 + 1, mid + 1, r, u, v);

    return merge(p1, p2);
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
        long long t;
        cin >> t;
        if (t == 1) {
            long long u, val;
            cin >> u >> val;
            update(1, 1, n, u, val);
        } else {
            long long u, v;
            cin >> u >> v;
            cout << query(1, 1, n, u, v) << "\n";
        }
    }
}