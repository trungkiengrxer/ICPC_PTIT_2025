// Cho ba xâu s1​,s2​,s3​. Tìm độ dài ngắn nhất của một xâu sao cho xâu đó chứa cả s1​, s2 và s3​.

// Input

// Gồm 3 dòng, mỗi dòng mô tả một xâu.

// Tất cả các xâu đều không rỗng, chỉ bao gồm các chữ cái Latinh viết thường.

// Độ dài của mỗi chuỗi không vượt quá 105.

// Output

// In ra một số duy nhất — là độ dài tối thiểu của một xâu mà chứa cả s1​,s2​ và s3​.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long MAX = 1e6 + 1;
const long long MOD = 1e9 + 7;
vector<long long> pow(MAX);

long long get_hash(string &s, vector<long long> &h, long long l, long long r) { return (h[r] - h[l - 1] * pow[r - l + 1] % MOD + MOD) % MOD; }

long long overlap(string &a, string &b) {
    long long n = a.size();
    long long m = b.size();
    long long len = min(n, m);

    vector<long long> hash_a(n + 1), hash_b(m + 1);
    pow[0] = 1;
    for (long long i = 1; i <= max(n, m); ++i) pow[i] = pow[i - 1] * 31 % MOD;
    for (long long i = 0; i < n; ++i) hash_a[i + 1] = (hash_a[i] * 31 + a[i] - 'a' + 1) % MOD;
    for (long long i = 0; i < m; ++i) hash_b[i + 1] = (hash_b[i] * 31 + b[i] - 'a' + 1) % MOD;

    long long result = 0;
    for (long long k = len; k >= 1; --k) {
        if (get_hash(a, hash_a, n - k + 1, n) == get_hash(b, hash_b, 1, k)) return k;
    }
    return result;
}

bool is_substring(string &a, string &b) {
    long long n = a.size();
    long long m = b.size();
    if (m > n) return false;

    vector<long long> hash_a(n + 1), hash_b(m + 1);
    pow[0] = 1;
    for (long long i = 1; i <= max(n, m); ++i) pow[i] = pow[i - 1] * 31 % MOD;
    for (long long i = 0; i < n; ++i) hash_a[i + 1] = (hash_a[i] * 31 + a[i] - 'a' + 1) % MOD;
    for (long long i = 0; i < m; ++i) hash_b[i + 1] = (hash_b[i] * 31 + b[i] - 'a' + 1) % MOD;

    for (long long i = 1; i + m - 1 <= n; ++i) {
        if (get_hash(a, hash_a, i, i + m - 1) == get_hash(b, hash_b, 1, m)) return true;
    }
    return false;
}

string merge(string &a, string &b) {
    if (is_substring(a, b)) return a;
    long long k = overlap(a, b);
    return a + b.substr(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y, z;
    cin >> x >> y >> z;
    long long ans = 1e9;
    vector<string> v = {x, y, z};
    sort(v.begin(), v.end());
    do {
        string t = merge(v[0], v[1]);
        string k = merge(t, v[2]);
        ans = min(ans, (long long)k.size());

    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
}