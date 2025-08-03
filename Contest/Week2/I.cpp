/*
Cho 3 số nguyên A, B và K. Trong các xâu có độ dài bằng A + B, gồm A kí tự ‘a’ và B kí tự ‘b’, hãy tìm xâu có thứ tự từ điển bằng K.

Input

Dữ liệu đầu vào gồm 3 số nguyên A, B và K (1 ≤ A, B ≤ 30, 1 ≤ K ≤ S với S là số lượng xâu có A kí tự ‘a’ và B kí tự ‘b’, S có giá trị không vượt quá phạm vi số nguyên 64 bit).
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<long long>> c(61, std::vector<long long>(61));

void combination() {
    for (long long i = 0; i < 61; ++i) {
        c[i][0] = c[i][i] = 1;
        for (long long j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

long long get(int a, int b) { return c[a + b][a]; }

int main() {
    combination();
    long long a, b, k;
    std::cin >> a >> b >> k;

    std::string result = "";
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

    result += std::string(a, 'a');
    result += std::string(b, 'b');
    std::cout << result;
}