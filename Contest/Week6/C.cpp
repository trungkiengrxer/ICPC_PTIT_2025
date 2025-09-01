/*
Cho hai số nguyên dương A và B đều có một chữ số. Hãy so sánh xâu được tạo bởi B lần copy chữ số A và A lần copy chữ số B, xem xâu nào có thứ tự từ điển nhỏ hơn?

Input: 

Input gồm hai số nguyên dương A và B (1 ≤ A, B ≤ 9).

Output: 

In ra một số nguyên là xâu có thứ tự từ điển nhỏ hơn.
*/

#include <iostream>
#include <string>

int main() {
    char a, b;
    std::cin >> a >> b;

    std::string str1 = std::string(a - '0', b);
    std::string str2 = std::string(b - '0', a);

    if (str1 < str2) {
        std::cout << str1;
    } else {
        std::cout << str2;
    }
}