#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> a(n), prefix(n, 0);

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // sort(a.begin(), a.end());

    for (long long i = 0; i < n; ++i) {
        if (i == 0) {
            prefix[i] = a[i];
            continue;
        }
        prefix[i] = prefix[i - 1] + a[i];
    }

    vector<long long> result;
    long long max_sum = -1;
    long long max_count = 1;

    for (long long k = 1; k <= n - 2; ++k) {
        long long sum = (prefix[n - 1] - prefix[k - 1]);
        // cout << avg << " " << k << "\n";
        if (sum * max_count > max_sum * (n - k)) {
            max_sum = sum;
            max_count = n - k;
            result.clear();
            result.push_back(k);
        } else if (sum * max_count == max_sum * (n - k)) {
            result.push_back(k);
        }
    }

    for (long long k : result) cout << k << " ";
}