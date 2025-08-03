#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;

    vector<unsigned long long> l(101);

    l[0] = 2;
    l[1] = 1;

    for (unsigned long long i = 2; i < 101; ++i) l[i] = l[i - 1] + l[i - 2];

    // for (unsigned long long x : l) cout << x << "\n";
    cout << l[n];
    return 0;
}