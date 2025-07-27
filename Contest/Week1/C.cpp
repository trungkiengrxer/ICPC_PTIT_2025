/*
Cho một xâu S. Nhiệm vụ của bạn là hãy tìm xâu con dài nhất có thể sao cho xâu con này có kí tự bắt đầu là ‘A’ và kết thúc bởi kí tự ‘Z’?

Input: 

Chứa một xâu S có độ dài không quá 200000, chỉ gồm các chữ cái in hoa.

Output: 

In ra độ dài xâu con dài nhất tìm được.
*/

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] == 'A' && s[right] == 'Z') break;
        else if (s[left] != 'A') ++left;
        else if (s[right] != 'Z') --right;
    }

    std::cout << right - left + 1;
}