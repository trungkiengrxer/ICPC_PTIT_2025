// Cho dãy số A[] có N phần tử và dãy số B[] có M phần tử. Nhiệm vụ của các bạn là hãy tìm 2 chỉ số i và j sao cho |A[i] – B[j]| là nhỏ nhất có thể.

// Input

// Dòng đầu tiên gồm hai số nguyên N và M (1 ≤ N, M ≤ 200000).

// Dòng thứ hai gồm N số nguyên A[i].

// Dòng thứ ba gồm M số nguyên B[j]. Các phần tử đều không âm và có giá trị không vượt quá 109.

// Output

// In ra một số nguyên là hiệu nhỏ nhất của hai phần tử trong hai dãy số đã cho.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    int res = 1e9;
    for(int x : a){
        // Tìm phần tử >= x trong b
        auto it = lower_bound(b.begin(), b.end(), x);

        if(it != b.end())
            res = min(res, abs(x - *it));
        if(it != b.begin()){
            --it;
            res = min(res, abs(x - *it));
        }
    }

    cout << res;
}
