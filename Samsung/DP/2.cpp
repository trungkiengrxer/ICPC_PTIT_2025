#include <iostream>
#include <vector>

using namespace std;

long long a, b, c, d, e;
vector<vector<long long>> w;

bool is_valid(long long x) {
    if (x == 0) return true;
    for (long long i = 1; i <= a - x + 1; ++i) {
        for (long long j = 1; j <= b - x + 1; ++j) {
            long long r1 = i;
            long long c1 = j;

            long long r2 = i + x - 1;
            long long c2 = j + x - 1;

            long long sum = w[r2][c2] - w[r1 - 1][c2] - w[r2][c1 - 1] + w[r1 - 1][c1 - 1];
            if (sum <= e) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a >> b >> c >> d >> e;

    vector<pair<long long, long long>> pair(c);
    w.assign(a + 1, vector<long long>(b + 1, 0));

    for (long long i = 0; i < c; ++i) {
        long long r, col;
        cin >> r >> col;
        w[r][col] = 1;
    }

    for (long long i = 1; i <= a; ++i) {
        for (long long j = 1; j <= b; ++j) {
            w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1] + w[i][j];
        }
    }

    long long result = 0;
    long long left = 1, right = min(a, b) / d;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long x = mid * d;
        if (is_valid(x)) {
            result = x;
            left = mid + 1;
        } else
            right = mid - 1;
    }

    cout << result;
}