// Cho một bảng kích thước N x N chỉ gồm các kí tự ‘#’ và ‘.’

// Nhiệm vụ của bạn là hãy chọn tối đa 2 ô ‘.’ rồi chuyển chúng sang ‘#’ sao cho tồn tại một dãy 6 kí tự liên tiếp theo hàng ngang, hàng dọc hoặc đường chéo.

// Input: 

// Dòng đầu tiên là số nguyên dương N (N ≤ 1000).

// N dòng tiếp theo, mỗi dòng là một xâu có N kí tự mô tả một hàng của bảng.

// Output: 

// In ra “Yes” nếu có thể tạo ra được dãy 6 kí tự ‘#’ liên tiếp, in ra “No” trong trường hợp ngược lại.


// BFS ra các vùng xung quanh (độ dài 6) thêm tham số chạy từ 0
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    vector<string> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    if (N < 6) { 
        cout << "No\n"; 
        return 0; 
    }

    int dx[4] = {0, 1, 1, 1}; 
    int dy[4] = {1, 0, 1, -1};

    auto inside = [&](int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    };

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

            for (int d = 0; d < 4; ++d) {
                int dots = 0;
                bool ok = true;
                
                for (int k = 0; k < 6; ++k) {
                    int x = i + dx[d]*k;
                    int y = j + dy[d]*k;
                    if (!inside(x, y)) { 
                        ok = false;
                        break; 
                    }
                    if (a[x][y] == '.') ++dots;
                }
                if (ok && dots <= 2) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
