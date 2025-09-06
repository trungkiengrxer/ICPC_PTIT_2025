#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const long long MOD = 1e9 + 9;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    vector<long long> b(m);

    for (long long i = 0; i < n; ++i) cin >> a[i];
    for (long long i = 0; i < m; ++i) cin >> b[i];

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));

    for (long long i = 0; i <= n; ++i) {
        for (long long j = 0; j <= m; ++j) dp[i][j][0] = 1;
    }

    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= m; ++j) {
            for (long long t = 1; t <= k; ++t) {
                dp[i][j][t] = dp[i - 1][j][t] + dp[i][j - 1][t] - dp[i - 1][j - 1][t];
                if (a[i - 1] > b[j - 1]) dp[i][j][t] += dp[i - 1][j - 1][t - 1];
                dp[i][j][t] = (dp[i][j][t] % MOD + MOD) % MOD;
            }
        }
    }
    cout << dp[n][m][k];
}