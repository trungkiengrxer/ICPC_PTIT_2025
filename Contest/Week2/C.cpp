#include <bits/stdc++.h>
using namespace std;

struct HalfEdge {
    int u, v;        // from u đến v
    double angle;    // góc của vector (v - u)
    int rev;         // chỉ số half-edge ngược lại (v -> u)
    int next;        // chỉ số half-edge tiếp theo trên cùng mặt
    bool used = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<array<int,4>> segs(N);
    for (int i = 0; i < N; i++) {
        cin >> segs[i][0] >> segs[i][1] >> segs[i][2] >> segs[i][3];
    }

    // 1) Đánh số các đỉnh
    map<pair<int,int>, int> mp;
    vector<pair<int,int>> pts;
    auto getId = [&](int x, int y) {
        pair<int,int> p = {x,y};
        if (!mp.count(p)) {
            int id = pts.size();
            pts.push_back(p);
            mp[p] = id;
        }
        return mp[p];
    };

    for (auto &s : segs) {
        getId(s[0], s[1]);
        getId(s[2], s[3]);
    }

    int V = pts.size();
    vector<HalfEdge> E;
    E.reserve(2 * N);

    // 2) Tạo nửa cạnh (half-edge)
    for (auto &s : segs) {
        int x1 = s[0], y1 = s[1], x2 = s[2], y2 = s[3];
        int u = getId(x1,y1);
        int v = getId(x2,y2);
        HalfEdge e1, e2;
        e1.u = u; e1.v = v;
        e2.u = v; e2.v = u;
        // tạm đặt rev, sẽ fix sau
        E.push_back(e1);
        E.push_back(e2);
    }
    // gắn chỉ số rev
    for (int i = 0; i < (int)E.size(); i += 2) {
        E[i].rev = i+1;
        E[i+1].rev = i;
    }

    // 3) Tính góc của mỗi half-edge
    for (auto &e : E) {
        auto [xu, yu] = pts[e.u];
        auto [xv, yv] = pts[e.v];
        e.angle = atan2(yv - yu, xv - xu);
    }

    // 4) Với mỗi đỉnh, tập hợp các half-edge xuất phát và sắp xếp theo góc
    vector<vector<int>> outgoing(V);
    for (int i = 0; i < (int)E.size(); i++) {
        outgoing[E[i].u].push_back(i);
    }
    for (int v = 0; v < V; v++) {
        auto &list = outgoing[v];
        sort(list.begin(), list.end(), [&](int a, int b){
            return E[a].angle < E[b].angle;
        });
    }

    // 5) Xác định chỉ số của mỗi half-edge trong hàng xuất phát của đỉnh u
    vector<int> pos(E.size());
    for (int v = 0; v < V; v++) {
        for (int i = 0; i < (int)outgoing[v].size(); i++) {
            pos[outgoing[v][i]] = i;
        }
    }

    // 6) Tính next cho mỗi half-edge: đi theo cạnh tiếp theo của mặt bên trái
    for (int i = 0; i < (int)E.size(); i++) {
        int rev = E[i].rev;
        int v = E[i].v;
        int d = outgoing[v].size();
        int p = pos[rev];
        // chọn cạnh ngay trước rev trong thứ tự CCW để đi tiếp
        int idx = (p - 1 + d) % d;
        E[i].next = outgoing[v][idx];
    }

    // 7) Lần theo từng half-edge để liệt kê mặt
    double sumSq = 0;
    for (int i = 0; i < (int)E.size(); i++) {
        if (E[i].used) continue;
        vector<int> face;
        int cur = i;
        // đi vòng cho đến khi quay lại i
        while (!E[cur].used) {
            E[cur].used = true;
            face.push_back(E[cur].u);
            cur = E[cur].next;
        }
        // tính diện tích polygon
        int m = face.size();
        if (m < 3) continue;
        double a = 0;
        for (int j = 0; j < m; j++) {
            auto [x1,y1] = pts[face[j]];
            auto [x2,y2] = pts[face[(j+1)%m]];
            a += (double)x1 * y2 - (double)x2 * y1;
        }
        a *= 0.5;
        // chỉ lấy các mặt có diện tích > 0 (các mặt hữu hạn)
        if (a > 0) {
            sumSq += a * a;
        }
    }

    cout << fixed << setprecision(6) << sumSq << "\n";
    return 0;
}