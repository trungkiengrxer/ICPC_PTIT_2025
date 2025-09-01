/*
Có N lá bài, mỗi lá bài có gắn với một con số nguyên dương A[i]. Bạn có thể chọn ngẫu nhiên ba lá bài rồi ghép chúng với nhau theo thứ tự tùy ý để tạo thành một con số mới.

Ví dụ như ba lá bài 1, 23, 4, bạn có thể tạo thành số 1234 hay 2314.

Hãy tìm số nguyên lớn nhất có thể tạo ra?

Input:

Dòng đầu tiên là số nguyên dương N (3 ≤ N ≤ 200000).

Dòng thứ hai nhập N số nguyên A[1], A[2], …, A[N] (1 ≤ A[i] ≤ 10^6).

Output:

In ra giá trị số nguyên lớn nhất tìm được.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i];

    sort(a.rbegin(), a.rend());

    std::vector<std::string> temp(3);
    temp[0] = std::to_string(a[0]);
    temp[1] = std::to_string(a[1]);
    temp[2] = std::to_string(a[2]);

    std::sort(temp.begin(), temp.end());
    std::string result = "";
    long long max = -1e9;

    do {
        std::string str_num = temp[0] + temp[1] + temp[2];
        long long num = std::stoll(str_num);
        if (num > max) {
            max = num;
            result = str_num;
        }
    } while (std::next_permutation(temp.begin(), temp.end()));

    std::cout << result;
}