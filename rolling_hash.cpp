/***************************************************************************************************
 *  Cho một đoạn văn bản gồm m ký tự; một đoạn mẫu gồm n ký tự.
 *  Xác định đoạn mẫu xuất hiện bao nhiêu lần trong đoạn văn bằng cách chỉ ra vị trí kí tựu đầu tiên
 * mà 2 đoạn trùng nhau.
 * (https://oj.vnoi.info/problem/substr)
 *      Lưu ý: Thuật toán được sử dụng trong bài này không chính xác tuyệt đối.
 *             Cần dùng nhiều modulo khác nhau để so sánh mã Hash (ví dụ như dùng 3 modulo một lúc).
 ****************************************************************************************************/

#include<iostream>
#include<string>

using namespace std;

const int BASE = 31;
const long long MOD = 1e9 + 7;
const long long MAX = 1e5 + 5;

long long Pow[MAX];     // pow[i] = BASE^i, dùng trong xác định hàm getHash bên dưới

void build(int n){
    Pow[0] = 1;
    for(int i = 1; i <= n; i++)
        Pow[i] = (Pow[i - 1] * BASE) % MOD;
}

long long getHash(long long Hash[], int left, int right){
    return (Hash[right] - Hash[left - 1] * Pow[right - left + 1] + MOD * MOD) % MOD;         
    // Cần +MOD*MOD để tránh kết quả âm xảy ra
}

int main(){
    string T, P;        // T: đoạn văn, P: đoạn mẫu
    getline(cin, T);
    getline(cin, P);

    int m = T.size(), n = P.size();
    T = " " + T;
    P = " " + P;

    // Chuẩn bị
    build(m);

    // Tính mã Hash cho đoạn mẫu
    long long hashP = 0;
    for(int i = 1; i <= n; i++)
        hashP = (hashP * BASE + P[i] - 'a' + 1) % MOD;

    // Tính mã Hash cho đoạn văn
    long long hashT[MAX] = {0};
    for(int i = 1; i <= m; i++)
        hashT[i] = (hashT[i - 1] * BASE + T[i] - 'a' + 1) % MOD;

    // Tìm kiếm
    for(int i = 1; i <= m - n + 1; ++i)
        if(getHash(hashT, i, i + n - 1) == hashP)
            cout << i << " ";
    return 0;
}