#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long MAX = 1e6 + 1;
const long long MOD = 1e9 + 7;
vector<long long> pow(MAX);
vector<long long> hash_a(MAX);


long long get_hash_a(long long i, long long j) { return (hash_a[j] - hash_a[i - 1] * pow[j - i + 1] + MOD * MOD) % MOD; }

int main() {
    string a, b;
    cin >> a >> b;

    long long n = a.size();
    long long m = b.size();

    a = " " + a;
    b = " " + b;

    pow[0] = 1;
    for (long long i = 1; i <= n; ++i) pow[i] = (pow[i - 1] * 26) % MOD;
    for (long long i = 1; i <= n; ++i) hash_a[i] = (hash_a[i - 1] * 26 + a[i] - 'a') % MOD;

    long long hash_b = 0;
    for (long long i = 1; i <= m; ++i) {
        hash_b = (hash_b * 26 + b[i] - 'a') % MOD;
    }
    for (long long i = 1; i <= n - m + 1; ++i) {
        if (hash_b == get_hash_a(i, i + m - 1)) {
            cout << i << " ";
        }
    }
}