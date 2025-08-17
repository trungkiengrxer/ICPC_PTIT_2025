/*
Trong chuyến du lịch, các bạn nam xung phong xách các túi hành lý cho cả đoàn. Tất nhiên mỗi người có thể xách được tối đa 2 túi nếu tổng trọng lượng 2 túi đó không vượt quá “ngưỡng” cho phép.

Hãy tính xem cần bao nhiêu bạn nam để mang được hết hành lý cho chuyến đi.

Input

Dòng đầu ghi 2 số N và C lần lượt là số túi xách và giá trị ngưỡng có thể xách được của một người. (1 ≤ N ≤ 105; 1 ≤ C ≤ 109)

Dòng thứ 2 ghi N số lần lượt là trọng lượng của từng túi. Biết rằng các trọng lượng đều nguyên dương và không quá C.  

Output

Ghi ra số bạn nam tối thiểu tính được.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int i = 0, j = n - 1, result = 0;
    while (i <= j) {
        if (a[i] + a[j] <= c) {
            ++i;
            --j;
        } else {
            --j;
        }
        ++result;
    }

    std::cout << result;
}