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
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long result = 0;
        long long diff = c - b;

        for (long long k = 1; k * diff < d; ++k) {
            long long l = (a + b * k) % d;
            long long r = (a + c * k) % d;

            bool is_ok;
            if (l <= r) {
                if (0 < l || 0 > r) is_ok = true;
                else is_ok = false;
            }
            else is_ok = false;
            if (is_ok) ++result;
        }
        
        cout << result << "\n";
    }
}