// Hexagram được định nghĩa là một ngôi sao 6 cánh đặc biệt. Mỗi giao điểm trong ngôi sao ghi một số nguyên dương sao cho tổng các số trong mỗi cạnh đều bằng nhau.
// Ví dụ với dãy số: 3 17 15 18 11 22 12 23 21 7 9 13
// Thì ta sẽ có 4 cách sắp xếp các số trên vào ngôi sao là:

// Bài toán đặt ra là cho trước dãy 12 số nguyên. Hãy đếm số cách xếp các số đó vào ngôi sao sáu cạnh để được dạng Hexagram như mô tả trên.
// Chú ý: Không xét các trường hợp là xoay của nhau hoặc lấy đối xứng.
// Input
// Dòng đầu ghi số bộ test T (T <= 100).
// Mỗi bộ test ghi trên một dòng 12 số nguyên dương, mỗi số cách nhau một khoảng trống. Các số đều được đảm bảo nhỏ hơn 1000000.
// Output
// Với mỗi bộ test, in ra màn hình số cách xếp các số trên để tạo thành HEXAGRAM như mô tả trên. 
// Ví dụ:
// Input
// Output
// 2
// 3 17 15 18 11 22 12 23 21 7 9 13
// 1 2 3 4 5 6 7 8 9 10 11 13
// 4
// 0Hexagram được định nghĩa là một ngôi sao 6 cánh đặc biệt. Mỗi giao điểm trong ngôi sao ghi một số nguyên dương sao cho tổng các số trong mỗi cạnh đều bằng nhau.
// Ví dụ với dãy số: 3 17 15 18 11 22 12 23 21 7 9 13
// Thì ta sẽ có 4 cách sắp xếp các số trên vào ngôi sao là:

// Bài toán đặt ra là cho trước dãy 12 số nguyên. Hãy đếm số cách xếp các số đó vào ngôi sao sáu cạnh để được dạng Hexagram như mô tả trên.
// Chú ý: Không xét các trường hợp là xoay của nhau hoặc lấy đối xứng.
// Input
// Dòng đầu ghi số bộ test T (T <= 100).
// Mỗi bộ test ghi trên một dòng 12 số nguyên dương, mỗi số cách nhau một khoảng trống. Các số đều được đảm bảo nhỏ hơn 1000000.
// Output
// Với mỗi bộ test, in ra màn hình số cách xếp các số trên để tạo thành HEXAGRAM như mô tả trên. 
// Ví dụ:
// Input
// Output
// 2
// 3 17 15 18 11 22 12 23 21 7 9 13
// 1 2 3 4 5 6 7 8 9 10 11 13
// 4
// Hexagram được định nghĩa là một ngôi sao 6 cánh đặc biệt. Mỗi giao điểm trong ngôi sao ghi một số nguyên dương sao cho tổng các số trong mỗi cạnh đều bằng nhau.
// Ví dụ với dãy số: 3 17 15 18 11 22 12 23 21 7 9 13
// Thì ta sẽ có 4 cách sắp xếp các số trên vào ngôi sao là:

// Bài toán đặt ra là cho trước dãy 12 số nguyên. Hãy đếm số cách xếp các số đó vào ngôi sao sáu cạnh để được dạng Hexagram như mô tả trên.
// Chú ý: Không xét các trường hợp là xoay của nhau hoặc lấy đối xứng.
// Input
// Dòng đầu ghi số bộ test T (T <= 100).
// Mỗi bộ test ghi trên một dòng 12 số nguyên dương, mỗi số cách nhau một khoảng trống. Các số đều được đảm bảo nhỏ hơn 1000000.
// Output
// Với mỗi bộ test, in ra màn hình số cách xếp các số trên để tạo thành HEXAGRAM như mô tả trên. 
// Ví dụ:
// Input
// Output
// 2
// 3 17 15 18 11 22 12 23 21 7 9 13
// 1 2 3 4 5 6 7 8 9 10 11 13
// 4
// 0

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Biến toàn cục để dễ sử dụng trong hàm đệ quy
std::vector<int> a(12);       // Lưu 12 số đầu vào
std::vector<int> p(12);       // Lưu hoán vị đang xây dựng
std::vector<bool> used(12);   // Đánh dấu các số đã được dùng
long long raw_solutions_count; // Đếm số lời giải thô (chưa chia cho đối xứng)
int S;                        // Tổng "kỳ diệu" của mỗi cạnh

// Hàm quay lui để tìm lời giải
void backtrack(int k) {
    // --- Cắt tỉa ---
    // Kiểm tra các phương trình ngay khi có đủ các thành phần
    // Điều này giúp loại bỏ các nhánh sai từ rất sớm.
    if (k == 5) {
        if (p[0] + p[1] + p[3] + p[4] != S) return;
    }
    if (k == 7) {
        if (p[1] + p[2] + p[5] + p[6] != S) return;
    }
    if (k == 9) {
        if (p[4] + p[5] + p[7] + p[8] != S) return;
    }
    if (k == 11) {
        if (p[6] + p[7] + p[9] + p[10] != S) return;
    }

    // --- Điều kiện dừng ---
    if (k == 12) {
        // Khi đã điền đủ 12 vị trí, kiểm tra 2 phương trình cuối cùng
        if ((p[8] + p[9] + p[11] + p[0] == S) && (p[10] + p[11] + p[2] + p[3] == S)) {
            raw_solutions_count++;
        }
        return;
    }

    // --- Bước đệ quy ---
    // Thử điền các số chưa dùng vào vị trí k
    for (int i = 0; i < 12; ++i) {
        if (!used[i]) {
            used[i] = true;
            p[k] = a[i];

            backtrack(k + 1);

            // Quay lui: trả lại trạng thái cũ để thử số khác
            used[i] = false;
        }
    }
}

void solve() {
    for (int i = 0; i < 12; ++i) {
        std::cin >> a[i];
    }

    long long total_sum = 0;
    for (int x : a) {
        total_sum += x;
    }

    // Điều kiện cần: tổng phải chia hết cho 3
    if (total_sum % 3 != 0) {
        std::cout << 0 << std::endl;
        return;
    }

    S = total_sum / 3;
    raw_solutions_count = 0;
    std::fill(used.begin(), used.end(), false);

    backtrack(0);

    // Kết quả cuối cùng là số lời giải thô chia cho 12 (số phép đối xứng)
    std::cout << raw_solutions_count / 12 << std::endl;
}

int main() {
    // Tăng tốc độ nhập xuất
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}