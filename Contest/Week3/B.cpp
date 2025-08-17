// Bạn có một dãy số không giảm (các phần tử được sắp xếp tăng dần hoặc bằng nhau) a1​,a2​,…,aN​. Bạn muốn phá hủy tính chất không giảm này bằng cách sử dụng một phép XOR hai phần tử kề nhau.

// Trong một bước, bạn có thể chọn hai phần tử liền kề trong dãy, ví dụ x và y. Xóa chúng khỏi dãy số và chèn vào vị trí đó phần tử mới có giá trị bằng x XOR y. Độ dài của dãy số giảm đi một sau mỗi thao tác. Thao tác này không thể thực hiện khi chỉ còn một phần tử.

// Ví dụ: Dãy số ban đầu là [1, 5, 6, 9]. Nếu chọn 5 và 6, thay thế chúng bằng 5 XOR 6 = 3, ta thu được [1, 3, 9].

// Yêu cầu: Tìm số bước (thao tác) tối thiểu cần thiết để làm cho dãy số không còn là dãy không giảm nữa. Nếu dãy số vẫn luôn không giảm mặc dù bạn thao tác như thế nào, hãy in ra -1.

// Input

// Dòng đầu tiên chứa một số nguyên N (2 ≤ N ≤ 105), là độ dài ban đầu của dãy số.

// Dòng thứ hai chứa N số nguyên a1​,a2​,…,aN​ (1 ≤ ai​ ≤ 109). Input đảm bảo rằng ai​ ≤ ai+1​.

// Output

// In ra một số nguyên duy nhất là số bước tối thiểu cần thiết. Nếu không có đáp án, hãy in -1.

// Test ví dụ:

// Input

// Output

// 4

// 2 5 6 8

// 1

// 3

// 1 2 3

// -1

// 4

// 11 22 71 92

// 2

//  

// Giải thích test 1: Chọn (2, 5), ta được dãy số mới sau 1 bước là (7, 6, 8).
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Hàm tìm MSB của một số (ví dụ: msb(13) = 8, msb(6) = 4)
// Dùng để kiểm tra trường hợp 3 số liên tiếp có cùng MSB -> đáp án là 1
int get_msb_val(int n) {
    if (n == 0) return 0;
    int k = 0;
    while ((1 << (k + 1)) <= n) {
        k++;
    }
    return 1 << k;
}

int main() {
    // Tăng tốc độ nhập xuất
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Tối ưu hóa: Nếu N đủ lớn, theo nguyên lý chuồng bồ câu
    // sẽ có 3 số có cùng MSB. Nếu chúng kề nhau, đáp án là 1.
    // Ngưỡng 61 là an toàn.
    if (n >= 61) {
        std::cout << 1 << std::endl;
        return 0;
    }
    
    // Một tối ưu hóa khác cho đáp án 1:
    // Kiểm tra nếu có 3 phần tử liền kề có cùng MSB
    for (int i = 0; i <= n - 3; ++i) {
        if (get_msb_val(a[i]) == get_msb_val(a[i+1]) && get_msb_val(a[i+1]) == get_msb_val(a[i+2])) {
            // Nếu a[i] ^ a[i+1] > a[i+2] hoặc a[i] > a[i+1] ^ a[i+2]
            // thì đáp án là 1. a[i] > a[i+1]^a[i+2] luôn đúng trong trường hợp này.
            std::cout << 1 << std::endl;
            return 0;
        }
    }


    int min_steps = -1;

    // Mảng XOR tiền tố để tính XOR của đoạn con trong O(1)
    std::vector<int> prefix_xor(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_xor[i + 1] = prefix_xor[i] ^ a[i];
    }

    // Duyệt qua tất cả các đoạn con [i, j]
    // i: chỉ số bắt đầu của đoạn
    for (int i = 0; i < n; ++i) {
        // j: chỉ số kết thúc của đoạn
        for (int j = i; j < n; ++j) {
            
            // So sánh đoạn [i..j] với phần tử bên phải a[j+1]
            if (j + 1 < n) {
                int left_xor_sum = prefix_xor[j + 1] ^ prefix_xor[i];
                if (left_xor_sum > a[j + 1]) {
                    int current_steps = j - i;
                    if (min_steps == -1 || current_steps < min_steps) {
                        min_steps = current_steps;
                    }
                }
            }

            // So sánh đoạn [i..j] với phần tử bên trái a[i-1]
            if (i > 0) {
                 int right_xor_sum = prefix_xor[j + 1] ^ prefix_xor[i];
                 if (a[i-1] > right_xor_sum) {
                    int current_steps = j - i;
                     if (min_steps == -1 || current_steps < min_steps) {
                        min_steps = current_steps;
                    }
                 }
            }
        }
    }

    std::cout << min_steps << std::endl;

    return 0;
}