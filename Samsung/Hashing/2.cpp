#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long n;
const long long MOD = 1e9 + 7;
const long long MAX = 1e6 + 1;
vector<long long> odd;
vector<long long> even;
vector<long long> pow(MAX);
vector<long long> hash_s(MAX);
vector<long long> hash_rs(MAX);

long long get_hash_s(long long i, long long j) { return (hash_s[j] - hash_s[i - 1] * pow[j - i + 1] + MOD * MOD) % MOD; }
long long get_hash_rs(long long i, long long j) { return (hash_rs[j] - hash_rs[i - 1] * pow[j - i + 1] + MOD * MOD) % MOD; }

bool check_palindrome(long long len) {
    if (len < 0 || len > n) return false;
    for (long long i = 1; i <= n - len + 1; ++i) {
        long long l1 = i, r1 = i + len - 1;
        long long l2 = n - r1 + 1, r2 = n - l1 + 1;
        if (get_hash_s(l1, r1) == get_hash_rs(l2, r2)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        odd.clear();
        even.clear();

        cin >> n;

        string s;
        cin >> s;

        string rs = s;
        reverse(rs.begin(), rs.end());

        s = " " + s;
        rs = " " + rs;

        for (long long i = 1; i <= n; i += 2) odd.push_back(i);
        for (long long i = 2; i <= n; i += 2) even.push_back(i);

        pow[0] = 1;
        for (long long i = 1; i <= n; ++i) pow[i] = (pow[i - 1] * 26) % MOD;
        for (long long i = 1; i <= n; ++i) hash_s[i] = (hash_s[i - 1] * 26 + s[i] - 'a') % MOD;
        for (long long i = 1; i <= n; ++i) hash_rs[i] = (hash_rs[i - 1] * 26 + rs[i] - 'a') % MOD;

        long long low = 0, high = odd.size() - 1;
        long long odd_res = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long len = odd[mid];
            if (check_palindrome(len)) {
                odd_res = len;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        low = 0, high = odd.size() - 1;
        long long even_res = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long len = even[mid];
            if (check_palindrome(len)) {
                even_res = len;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        cout << max(odd_res, even_res) << "\n";
    }
}