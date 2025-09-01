/*
Dãy ngoặc đúng được định nghĩa như sau:

Một xâu rỗng được coi là một dãy ngoặc đúng.
Nếu A và B là dãy ngoặc đúng thì xâu AB cũng là một dãy ngoặc đúng.
Nếu A là dãy ngoặc đúng thì (A) cũng là một dãy ngoặc đúng.
Cho xâu S chứa các kí tự (, ), và một kí tự *.

Nhiệm vụ của bạn là hãy đếm xem có bao nhiêu cặp dấu ngoặc tương ứng xung quanh kí tự *. Cặp kí tự SL và SR được gọi là cặp dấu ngoặc tương ứng nếu như SL là kí tự mở ngoặc, SR là kí tự đóng ngoặc và xâu con từ vị trí SL đến SR khi bỏ kí tự * đi là một dãy ngoặc đúng.

Input

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

Mỗi test gồm một xâu S có không quá 1000 kí tự.

Output

Với mỗi test, hãy in ra kết quả tìm được trên một dòng.
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        int start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                start = i;
                break;
            }
        }

        int count = 0;
        for (int i = 0; i < start; ++i) {
            if (s[i] == '(') {
                int balance = 1;
                for (int j = i + 1; j < s.size(); ++j) {
                    if (s[j] == '(')
                        ++balance;
                    else if (s[j] == ')')
                        --balance;
                    if (balance < 0) break;
                    if (balance == 0 && j > start) ++count;
                }
            }
        }

        std::cout << count << "\n";
    }
}