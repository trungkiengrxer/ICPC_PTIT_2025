#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<long long>> c(61, vector<long long>(61));

void combination() {
    for (long long i = 0; i < 61; ++i) {
        c[i][0] = c[i][i] = 1;
        for (long long j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

long long get(long long a, long long b) {
    return c[a + b][a];
}

int main() {
    combination();
    long long a, b, k;
    cin >> a >> b >> k;

    string result = "";

    while (a > 0 && b > 0) {
        long long count = get(a - 1, b);
        if (k <= count) {
            result += "a";
            --a;
        } else {
            result += "b";
            k -= count;
            --b;
        }
    }

    result += string(a, 'a');
    result += string(b, 'b');

    cout << result;
}

