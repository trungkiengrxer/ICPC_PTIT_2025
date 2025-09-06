#include <iostream>
#include <set>
#include <vector>

using namespace std;

multiset<int> l, r;

void balance() {
    while (l.size() > r.size() + 1) {
        auto it = prev(l.end());
        r.insert(*it);
        l.erase(it);
    }
    while (l.size() < r.size()) {
        auto it = r.begin();
        l.insert(*it);
        r.erase(it);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int q;
    cin >> q;

    while (q--) {
        string c;
        cin >> c;
        if (c == "add") {
            int x;
            cin >> x;
            if (l.empty() || x < *prev(l.end())) {
                l.insert(x);
            } else {
                r.insert(x);
            }
            balance();
        } else if (c == "del") {
            int x;
            cin >> x;
            auto it = l.find(x);
            if (it != l.end()) l.erase(it);
            else {
                it = r.find(x);
                if (it != r.end()) r.erase(it);
            }
            balance();
        } else {
            cout << *prev(l.end()) << "\n";
        }
    }
}