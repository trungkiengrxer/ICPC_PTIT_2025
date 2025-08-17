// Cho số nguyên abc có 3 chữ số, trong đó cả 3 chữ số đều khác 0.

// Hãy tính tổng abc + bca + cab.

// Input:

// Đầu vào chứa một số nguyên có ba chữ số.

// Output:

// In ra một số nguyên là đáp án tìm được.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0 ; i < 3 ; i++){
        ans += n;
        int d = n % 10;
        n /= 10;
        n += d * 100;
    }
    cout << ans;
}
