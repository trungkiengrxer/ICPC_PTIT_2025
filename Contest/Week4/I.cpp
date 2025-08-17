// Cho số nguyên dương N. Tại mỗi bước, bạn có thể tăng N thêm 1 đơn vị (gán N = N + 1).

// Hãy tìm số bước tối thiểu để biến tổng các chữ số của N nhỏ hơn hoặc bằng giá trị S cho trước.

// Input:

// Dòng đầu ghi số lượng bộ test T (T ≤ 20000).

// Mỗi bộ test gồm 2 số nguyên N và S (1 ≤ N ≤ 1018, 1 ≤ S ≤ 162).

// Output:

// Với mỗi test, trên một dòng, in ra một số duy nhất là số bước tối thiểu để biến tổng các chữ số của N nhỏ hơn hoặc bằng S.


// Ý tưởng: nếu số khác 0 thì càng tăng thì tổng càng giảm nên là cộng vào cho nó bằng 0 ở mỗi hàng


#include <bits/stdc++.h>
using namespace std;

int sum(long long n){
    int res = 0;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n,s;
        cin >> n >> s;
        if(sum(n) > s){
            long long ans = 0;
            long long tmp = 1;
            while(sum(n) > s){
                int d = (n / tmp) % 10;  // chữ số tại vị trí tmp
                if(d != 0){
                    long long add = tmp * (10 - d); // số cần cộng để biến chữ số này thành 0
                    n += add;   // cập nhật N
                    ans += add; // cộng vào số bước
                }
                tmp *= 10; // chuyển sang chữ số kế tiếp (hàng chục, hàng trăm,...)
            }

            cout << ans << endl;
        }
        else cout << 0 << endl;
    }
}
