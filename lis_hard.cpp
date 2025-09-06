#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lnds(const std::string &s) {
    vector<char> tail;

    for (char c : s) {
        auto it = std::upper_bound(tail.begin(), tail.end(), c);
        if (it == tail.end())
            tail.push_back(c);
        else
            *it = c;
    }

    return tail.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        cout << lnds(s) << "\n";
    }
    return 0;
}
