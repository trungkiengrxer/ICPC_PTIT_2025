#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m, q;
vector<string> a;
vector<vector<int>> d;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    deque<pair<int, int>> deque;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '*') {
                d[i][j] = 0;
                deque.push_back({i, j});
            }
        }
    }

    while (!deque.empty()) {
        auto [x, y] = deque.front();
        deque.pop_front();

        for (int k = 0; k < 4; ++k) {
            int new_x = x + dx[k];
            int new_y = y + dy[k];

            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;

            int s = 0;
            if (a[new_x][new_y] != a[x][y]) s = 1;
            if (d[new_x][new_y] > d[x][y] + s) {
                d[new_x][new_y] = d[x][y] + s;
                if (s == 0)
                    deque.push_front({new_x, new_y});
                else
                    deque.push_back({new_x, new_y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> q;

    a.resize(n);
    d.assign(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; ++i) cin >> a[i];

    bfs();

    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        
        if (d[x][y] == 1e9) cout << "-1\n";
        else cout << d[x][y] << "\n";
    }
}