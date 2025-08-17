/*
Cho xâu S chỉ gồm các kí tự thường. Nhiệm vụ của bạn là hãy tìm xâu thứ K trong tất cả các xâu được tạo ra là hoán vị của xâu S đã cho.

Input: 

Dữ liệu đầu vào gồm xâu S và số nguyên K. Xâu S có độ dài không quá 8 kí tự.

Input đảm bảo đáp án có tồn tại.

Output: 

Hãy in ra xâu tìm được.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    int k;
    std::cin >> s >> k;

    std::sort(s.begin(), s.end());
    std::vector<std::string> result;

    int count = 0;
    do {
        result.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    std::sort(result.begin(), result.end());
    std::cout << result[k - 1];
}