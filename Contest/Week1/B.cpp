/*
Cho xâu S độ dài N và K từ trong trong từ điển. Tính số cách ghép các từ trong từ điển để tạo thành xâu S (một từ có thể sử dụng nhiều lần).

Input:

Dòng đầu nhập xâu S độ dài bằng N (1 ≤ N ≤ 5000).

Dòng thứ hai nhập số nguyên K (1 ≤ K ≤ 105).

K dòng sau, mỗi dòng nhập một từ có trong từ điển. Input đảm bảo các từ trong từ điển là phân biệt.

Output:

In ra số cách ghép từ theo modulo 1.000.000.007
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

const int MAX = 1000005;
const long long MOD = 1e9 + 7;

int count = 1;
std::vector<std::vector<int>> trie(MAX, std::vector<int>(27, 0));
std::vector<bool> is_end(MAX, false);

void insert(std::string &t) {
    int u = 0;
    for (char c : t) {
        int v = c - 'a';
        if (!trie[u][v]) trie[u][v] = count++;
        u = trie[u][v];
    }
    is_end[u] = true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.size();

    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::string t;
        std::cin >> t;
        insert(t);
    }
    std::vector<long long> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (!dp[i]) continue;
        int u = 0;
        for (int j = i + 1; j <= n; ++j) {
            int v = s[j - 1] - 'a';
            if (!trie[u][v]) break;
            u = trie[u][v];

            // số cách tạo ra xâu s[0...j] = s[0...i - 1] + s[i...j]
            if (is_end[u]) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }
    }

    std::cout << dp[n] << "\n";
}