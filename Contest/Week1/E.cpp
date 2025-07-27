/*
Tí và Tèo cùng chơi trò chơi đối kháng như sau:

1) Có n viên sỏi trong rổ, mỗi lượt, người chơi sẽ bốc 1 số viên sỏi trong rổ (ít nhất 1 viên và nhiều nhất là n viên). Tí là người đi trước, 2 người chơi luân phiên nhau.

2) Mỗi lượt, người chơi bốc ít nhất 1 viên, và nhiều nhất bằng 2 lần số viên sỏi mà người chơi trước vừa bốc. Lượt chơi đầu tiên Tí có thể bốc bao nhiêu tùy ý.

3) Người chơi nào lấy được viên sỏi cuối cùng sẽ là người chiến thắng.

Các bạn hãy xác định xem số viên sỏi nhỏ nhất Tí có thể bốc ở lượt đầu tiên để đảm bảo mình chắc chắn chiến thắng.

Input:

Một số nguyên dương duy nhất n (n <= 10^15) là số viên sỏi có ban đầu.

Output:

In ra số viên sỏi nhỏ nhất Tí bốc ở lượt đầu tiên để đảm bảo mình sẽ thắng cuộc.
*/

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<long long> fibo(48);

void fibonacci() {
    fibo[0] = 0;
    fibo[1] = 1;

    for (long long i = 2; i < 48; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2];
}

int main() {
    fibonacci();
    long long n, result = 0;
    std::cin >> n;

    if (std::binary_search(fibo.begin(), fibo.end(), n)) {
        std::cout << n;
        return 0;
    }

    while (n > 0) {
        auto it = std::upper_bound(fibo.begin(), fibo.end(), n);
        --it;
        long long f = *it;
        result = f;
        n -= f;
    }

    std::cout << result;
}