#include <iostream>
#include <vector>

using namespace std;
const long long MAX = 1e5 + 5;

vector<long long> a(MAX);
vector<long long> tree(MAX * 4);

void build(long long idx, long long l, long long r) {
    if (l == r) {
        tree[idx] = a[l];
        return;
    }

    long long mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

void update(long long idx, long long l, long long r, long long u, long long k) {
    if (l == r) {
        tree[idx] += k;
        return;
    }

    long long mid = (l + r) / 2;
    if (u <= mid) {
        update(2 * idx, l, mid, u, k);
    } else {
        update(2 * idx + 1, mid + 1, r, u, k);
    }
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

long long query(long long idx, long long l, long long r, long long u, long long v) {
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return tree[idx];

    long long mid = (l + r) / 2;
    long long p1 = query(idx * 2, l, mid, u, v);
    long long p2 = query(idx * 2 + 1, mid + 1, r, u, v);

    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, q;
    cin >> n;
    for (long long i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    cin >> q;
    while (q--) {
        long long t;
        cin >> t;
        if (t == 1) {
            long long u, k;
            cin >> u >> k;
            update(1, 1, n, u, k);
        } else {
            long long u, v;
            cin >> u >> v;
            cout << query(1, 1, n, u, v) << "\n";
        }
    }
}