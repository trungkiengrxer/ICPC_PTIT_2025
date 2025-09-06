#include <iostream>
#include <vector>

using namespace std;
const long long MOD = 1e9 + 7;

vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    vector<vector<long long>> result(2, vector<long long>(2, 0));

    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < 2; ++j) {
            for (long long k = 0; k < 2; ++k) {
                result[i][j] += (a[i][k] * b[k][j]);
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

vector<vector<long long>> bin_pow(vector<vector<long long>> &a, long long exp) {
    vector<vector<long long>> result(2, vector<long long>(2, 0));
    result[0][0] = 1;
    result[1][1] = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, a);
        }

        a = multiply(a, a);
        exp /= 2;
    }

    return result;
}

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<vector<long long>> a(2, vector<long long>(2, 0));
        a[0][0] = 1;
        a[0][1] = 1;
        a[1][0] = 1;

        vector<vector<long long>> result = bin_pow(a, n);
        cout << result[0][1] << "\n";
    }
}