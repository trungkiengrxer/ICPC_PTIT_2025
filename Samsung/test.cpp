#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

struct Node {
    int cnt;
    ll mn;
    ll leftVal;
    ll rightVal;
    Node(): cnt(0), mn(INF), leftVal(INF), rightVal(-INF) {}
};

vector<Node> seg;
vector<ll> coords;
vector<int> freq; // real counts at leaves

Node mergeNode(const Node &a, const Node &b) {
    if (a.cnt == 0) return b;
    if (b.cnt == 0) return a;
    Node res;
    res.cnt = a.cnt + b.cnt;
    res.leftVal = a.leftVal;
    res.rightVal = b.rightVal;
    res.mn = min(a.mn, b.mn);
    // cross gap between rightmost of a and leftmost of b
    res.mn = min(res.mn, b.leftVal - a.rightVal);
    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx].cnt = freq[l];
        if (freq[l] == 0) {
            seg[idx].mn = INF;
            seg[idx].leftVal = INF;
            seg[idx].rightVal = -INF;
        } else {
            seg[idx].leftVal = seg[idx].rightVal = coords[l];
            seg[idx].mn = (freq[l] >= 2 ? 0 : INF);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid);
    build(idx<<1|1, mid+1, r);
    seg[idx] = mergeNode(seg[idx<<1], seg[idx<<1|1]);
}

void pointUpdate(int idx, int l, int r, int pos) {
    if (l == r) {
        // freq[pos] already updated outside before calling
        seg[idx].cnt = freq[pos];
        seg[idx].leftVal = seg[idx].rightVal = coords[pos];
        seg[idx].mn = (freq[pos] >= 2 ? 0 : INF);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) pointUpdate(idx<<1, l, mid, pos);
    else pointUpdate(idx<<1|1, mid+1, r, pos);
    seg[idx] = mergeNode(seg[idx<<1], seg[idx<<1|1]);
}

Node rangeQuery(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return Node(); // empty
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) >> 1;
    Node left = rangeQuery(idx<<1, l, mid, ql, qr);
    Node right = rangeQuery(idx<<1|1, mid+1, r, ql, qr);
    return mergeNode(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Read queries first to collect all inserted coordinates
    struct Query { int type; ll x, y; }; // type 1: x=P ; type 2: x=L, y=R
    vector<Query> queries;
    queries.reserve(M);
    vector<ll> allCoords;
    allCoords.reserve(N + M);
    for (int i = 0; i < N; ++i) allCoords.push_back(A[i]);

    for (int i = 0; i < M; ++i) {
        int t; cin >> t;
        if (t == 1) {
            ll P; cin >> P;
            queries.push_back({1, P, 0});
            allCoords.push_back(P);
        } else {
            ll L, R; cin >> L >> R;
            queries.push_back({2, L, R});
            // Note: L,R are not necessarily in coords; we will use lower_bound/upper_bound on coords
        }
    }

    // coordinate compression: unique sorted coords from initial points and all P inserts
    sort(allCoords.begin(), allCoords.end());
    allCoords.erase(unique(allCoords.begin(), allCoords.end()), allCoords.end());
    coords = allCoords;
    int U = (int)coords.size();
    freq.assign(U, 0);

    // map initial A to indices and count freq
    for (ll v : A) {
        int idx = int(lower_bound(coords.begin(), coords.end(), v) - coords.begin());
        freq[idx] ++;
    }

    // build segment tree
    seg.assign(4 * max(1, U), Node());
    if (U > 0) build(1, 0, U-1);

    // process queries online
    for (auto &q : queries) {
        if (q.type == 1) {
            // insert point q.x
            int idx = int(lower_bound(coords.begin(), coords.end(), q.x) - coords.begin());
            freq[idx] ++;
            pointUpdate(1, 0, U-1, idx);
        } else {
            ll L = q.x, R = q.y;
            if (U == 0) {
                cout << -1 << '\n';
                continue;
            }
            // find leftmost index with coord >= L
            int lidx = int(lower_bound(coords.begin(), coords.end(), L) - coords.begin());
            // find rightmost index with coord <= R
            int ridx = int(upper_bound(coords.begin(), coords.end(), R) - coords.begin()) - 1;
            if (lidx > ridx || lidx >= U || ridx < 0) {
                cout << -1 << '\n';
                continue;
            }
            Node res = rangeQuery(1, 0, U-1, lidx, ridx);
            if (res.cnt < 2) cout << -1 << '\n';
            else cout << res.mn << '\n';
        }
    }

    return 0;
}
