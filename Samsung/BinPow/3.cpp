#include <iostream>
#include <vector>

using namespace std;
unsigned long long MOD;

unsigned long long modulo_multiply(unsigned long long a, unsigned long long b) {
    unsigned long long result = 0;
    a = a % MOD;
    while (b > 0) {
        if (b % 2 == 1) result = (result + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return result;
}
vector<vector<unsigned long long>> multiply(vector<vector<unsigned long long>> &a, vector<vector<unsigned long long>> &b) {
    vector<vector<unsigned long long>> result(3, vector<unsigned long long>(3, 0));

    for (unsigned long long i = 0; i < 3; ++i) {
        for (unsigned long long j = 0; j < 3; ++j) {
            for (unsigned long long k = 0; k < 3; ++k) {
                result[i][j] += (modulo_multiply(a[i][k], b[k][j]));
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

vector<vector<unsigned long long>> bin_pow(vector<vector<unsigned long long>> &a, unsigned long long exp) {
    vector<vector<unsigned long long>> result(3, vector<unsigned long long>(3, 0));
    result[0][0] = 1;
    result[1][1] = 1;
    result[2][2] = 1;

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
    unsigned long long t;
    cin >> t;

    while (t--) {
        unsigned long long n;
        cin >> n >> MOD;

        if (n <= 3) {
            cout << n << "\n";
            continue;
        }

        vector<vector<unsigned long long>> a(3, vector<unsigned long long>(3, 0));
        a[0][0] = 1;
        a[0][1] = 2;
        a[0][2] = 3;
        a[1][0] = 1;
        a[2][1] = 1;

        vector<vector<unsigned long long>> result = bin_pow(a, n - 3);
        long long res = 0;
        res = (res + modulo_multiply(result[0][0], 3)) % MOD;
        res = (res + modulo_multiply(result[0][1], 2)) % MOD;
        res = (res + modulo_multiply(result[0][2], 1)) % MOD;
        cout << res << "\n";
    }
}