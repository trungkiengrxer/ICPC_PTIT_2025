#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll modexp(ll a, ll e) {
    ll r = 1;
    a %= MOD;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        ll K;
        cin >> N >> K;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        unordered_map<ll,int> cnt;
        cnt.reserve(N * 2);
        for (auto v : A) {
            cnt[v]++;
        }

        ll answer = 1;
        for (auto &p : cnt) {
            ll v = p.first;
            if (K > 0 && cnt.find(v - K) != cnt.end()) {
                continue;
            }
            ll dp0 = 1;  
            ll dp1 = 0;  
            ll cur = v;
            while (true) {
                auto it = cnt.find(cur);
                if (it == cnt.end()) break;
                int c = it->second;

                ll non_empty = (modexp(2, c) + MOD - 1) % MOD;
                if (dp1 == 0 && dp0 == 1) {
                    ll ndp0 = dp0;       
                    ll ndp1 = non_empty; 
                    dp0 = ndp0;
                    dp1 = ndp1;
                } else {
                    ll ndp0 = (dp0 + dp1) % MOD;       
                    ll ndp1 = dp0 * non_empty % MOD;      
                    dp0 = ndp0;
                    dp1 = ndp1;
                }
                cur += K;
            }
            ll ways = (dp0 + dp1) % MOD;
            answer = answer * ways % MOD;
        }

        answer = (answer + MOD - 1) % MOD;
        cout << answer << "\n";
    }
    return 0;
}