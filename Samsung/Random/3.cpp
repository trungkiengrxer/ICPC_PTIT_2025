#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long x, y, z;
    cin >> x >> y >> z;

    cout << ((x + y - 1) * (x + y)) / 2 - x + 1 << "\n";

    long long diag = (-1 + sqrt(8 * (long double)z - 7)) / 2 + 1;

    long long last = (diag * (diag + 1)) / 2;

    long long i = last - z + 1;
    long long j = diag - i + 1;

    cout << i << " " << j << "\n";

}