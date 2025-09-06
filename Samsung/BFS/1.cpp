#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string s;
string e;

string rotate_left(string a) {
    string temp = a;

    temp[0] = a[3];
    temp[1] = a[0];
    temp[2] = a[2];
    temp[3] = a[4];
    temp[4] = a[1];
    temp[5] = a[5];

    a = temp;
    return a;
}

string rotate_right(string a) {
    string temp = a;

    temp[0] = a[0];
    temp[1] = a[4];
    temp[2] = a[1];
    temp[3] = a[3];
    temp[4] = a[5];
    temp[5] = a[2];

    a = temp;
    return a;
}

int bfs() {
    queue<string> queue;
    unordered_map<string, int> map;

    map[s] = 0;
    queue.push(s);

    while (!queue.empty()) {
        string top = queue.front();
        queue.pop();

        int dis = map[top];

        string left = rotate_left(top);
        if (!map.count(left)) {
            map[left] = dis + 1;
            if (left == e) return map[left];
            queue.push(left);
        }

        string right = rotate_right(top);
        if (!map.count(right)) {
            map[right] = dis + 1;
            if (right == e) return map[right];
            queue.push(right);
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for (int i = 0; i < 6; ++i) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    for (int i = 0; i < 6; ++i) {
        char c;
        cin >> c;
        e.push_back(c);
    }

    cout << bfs();
}