/*
Một khu du lịch có YSf0nPffq+LjhrDLWbLy3ph4hzeTY2vLFCu1UMmB+1f9MEGve6364Zayhzqu3Kz4Lx2PxgAAAABJRU5ErkJggg== hòn đảo, hòn đảo z+wAAAABJRU5ErkJggg== có độ cao OqDyCYbPqlVJXV1uMUdnxByebjQpMG6S2+ZiSYiHP8RuWfhy9YWmzpiFBXS7G6k0EKEhUHetrFPcC8DNivBvjHT8tx9oVmRXXpzyC+Udyeq+qWbEv5kAAAAASUVORK5CYII=. Để di chuyển từ hòn đảo z+wAAAABJRU5ErkJggg== đến hòn đảo PwM2wIRVFCg4KoERMgMQJHcmWjMyMqZvR4+PO1tXHWNgsNJSZWBgJDtqIYaDAMgCEAAaBQW3J1gB+VYTboP5GD7XUVNB17EtDSiStg2qH6Hjzq0rUJeCdcAlIF6AG4SQuH0N5jVoDECNBFsAcxGSq8AWIBkEtwPDIKgHMQyCehDTIEiQQMIC7jWIcxhub8MmDM5mVmnQcEOEJ5BFfkQNSEoEAOu1qTMlBLGTAAAAAElFTkSuQmCC du khách có thể sử dụng tàu lượn với chi phí là w7xIzE2v0+cKhb7Jcno6PsZLxke6aezAKsgdCj9OK4THPuotva2pgD7zzOxnT1YHPdb5wN5sLRDQXORne584SBM2cXjm4gcDa6y50nDJw5u3B0A4Gz0V3uPGHgzNmFoxv4D583x8eY22BIAAAAAElFTkSuQmCC. Tuy nhiên, sau một thời gian cho thuê tàu lượn, các nhà thầu đã áp giá sàn cho đảo thứ z+wAAAABJRU5ErkJggg== là qXp9Kl6QHsQAAAABJRU5ErkJggg==, cụ thể để di chuyển từ đảo z+wAAAABJRU5ErkJggg== đến đảo PwM2wIRVFCg4KoERMgMQJHcmWjMyMqZvR4+PO1tXHWNgsNJSZWBgJDtqIYaDAMgCEAAaBQW3J1gB+VYTboP5GD7XUVNB17EtDSiStg2qH6Hjzq0rUJeCdcAlIF6AG4SQuH0N5jVoDECNBFsAcxGSq8AWIBkEtwPDIKgHMQyCehDTIEiQQMIC7jWIcxhub8MmDM5mVmnQcEOEJ5BFfkQNSEoEAOu1qTMlBLGTAAAAAElFTkSuQmCC, chi phí tính mới là: cVxGSS9D9wHRGXiyu1FkyzZbuP2ou0MmeBzLJpkyXYbx6LtDJngcyyaZMl2G8ei7QyZ4HMsmmTJdhvHou0MmeD7D4akHhgHcGvkAAAAAElFTkSuQmCC.

Một du khách muốn đi thăm tất cả YSf0nPffq+LjhrDLWbLy3ph4hzeTY2vLFCu1UMmB+1f9MEGve6364Zayhzqu3Kz4Lx2PxgAAAABJRU5ErkJggg== hòn đảo bằng tàu lượn theo cách: bắt đầu từ hòn đảo LKZgAAAABJRU5ErkJggg==, sử dụng tàu lượn để tới các hòn đảo khác, mỗi hòn đảo thăm đúng một lần rồi quay lại hòn đảo LKZgAAAABJRU5ErkJggg==.

Yêu cầu: Hãy giúp du khách tìm hành trình di chuyển với tổng chi phí nhỏ nhất.

Input

Dòng đầu chứa số nguyên dương N7IoyVbYorQoyQiQGbKqtCjJCJAZ+guiiKy5S9e0DAAAAABJRU5ErkJggg==;

Dòng thứ S644yRW87yo4yBQEKDedlR5mCAIXGf2WbXIAwFLxcAAAAAElFTkSuQmCC trong YSf0nPffq+LjhrDLWbLy3ph4hzeTY2vLFCu1UMmB+1f9MEGve6364Zayhzqu3Kz4Lx2PxgAAAABJRU5ErkJggg== dòng sau chứa hai số nguyên không âm 5PlLzTp9yGcXWfs71CfQ79PwgP0X2ImEWaMkUQFjJcmIUNUmESYMUYSFTBemoQMUWESYcYYSVTAeGkSMn8BddYoK+nK9WEAAAAASUVORK5CYII=.

Output

Ghi ra một số là tổng chi phí nhỏ nhất tìm được.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

struct Island {
    long long h;
    long long p;
    Island(long long h_data, long long p_data) {
        h = h_data;
        p = p_data;
    }
    bool operator<(const Island &other) const { return h < other.h; }
};


// max(p_i, h_i - h_j) = p_i + max(h_j - (h_j + p_i))
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, main_cost = 0;
    std::cin >> n;
    std::vector<Island> a;

    for (long long i = 0; i < n; ++i) {
        long long h, p;
        std::cin >> h >> p;
        a.push_back({h, p});
        main_cost += p;
    }

    std::sort(a.begin() + 1, a.end());

    long long cost = a[0].h + a[0].p;
    std::priority_queue<long long> priority_queue;
    long long idx = 1, second_cost = 0;

    // cost tương ứng là h_i + p_i, cần tìm sao cho cost lớn nhất
    // để hj - cost min
    while (idx < n && !priority_queue.empty()) {
        while (idx < n && a[idx].h <= cost) {
            priority_queue.push(a[idx].h + a[idx].p);
            ++idx;
        }
        if (!priority_queue.empty()) {
            cost = std::max(cost, priority_queue.top());
            priority_queue.pop();
        } else {
            second_cost += a[idx].h - cost;
            cost = a[idx].h + a[idx].p;
            ++idx;
        }
    }

    std::cout << main_cost + second_cost;
}