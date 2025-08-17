#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        long long m, n;
        cin >> m >> n;

        vector<vector<long long>> a(m, vector<long long>(n));

        long long area = 0;
        for (long long i = 0; i < m; ++i) {
            for (long long j = 0; j < n; ++j) {
                cin >> a[i][j];
                if (a[i][j] > 0) area += 2;
            }
        }

        long long dx[4] = {-1, 1, 0, 0};
        long long dy[4] = {0, 0, -1, 1};

        for (long long i = 0; i < m; ++i) {
            for (long long j = 0; j < n; ++j) {
                for (long long k = 0; k < 4; ++k) {
                    long long new_i = i + dx[k];
                    long long new_j = j + dy[k];
                    long long s = 0;
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                        s = a[new_i][new_j];
                    }
                    area += max((long long)0, a[i][j] - s);
                }
            }
        }

        cout << area << "\n";
    }
}