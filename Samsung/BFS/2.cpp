#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string a, s = "1238004765";

string rotate_left(string a) {
    string result = a;
    result[0] = a[3];
    result[1] = a[0];
    result[2] = a[2];
    result[3] = a[7];
    result[4] = a[4];
    result[5] = a[1];
    result[6] = a[6];
    result[7] = a[8];
    result[8] = a[5];
    result[9] = a[9];
    return result;
}

string rotate_right(string a) {
    string result = a;
    result[0] = a[0];
    result[1] = a[4];
    result[2] = a[1];
    result[3] = a[3];
    result[4] = a[8];
    result[5] = a[5];
    result[6] = a[2];
    result[7] = a[7];
    result[8] = a[9];
    result[9] = a[6];
    return result;
}

string r_rotate_left(string a) {
    string result = a;

    result[3] = a[0];
    result[0] = a[1];
    result[2] = a[2];
    result[7] = a[3];
    result[4] = a[4];
    result[1] = a[5];
    result[6] = a[6];
    result[8] = a[7];
    result[5] = a[8];
    result[9] = a[9];

    return result;
}

string r_rotate_right(string a) {
    string result = a;
    result[0] = a[0];
    result[4] = a[1];
    result[1] = a[2];
    result[3] = a[3];
    result[8] = a[4];
    result[5] = a[5];
    result[2] = a[6];
    result[7] = a[7];
    result[9] = a[8];
    result[6] = a[9];
    return result;
}

int bfs() {
    queue<string> queue1;
    queue<string> queue2;
    unordered_map<string, int> dist1;
    unordered_map<string, int> dist2;

    dist1[a] = 0;
    dist2[s] = 0;
    queue1.push(a);
    queue2.push(s);

    while (!queue1.empty()) {
        string top = queue1.front();
        queue1.pop();

        if (dist1[top] >= 15) break;

        string left = rotate_left(top);
        if (!dist1.count(left)) {
            dist1[left] = dist1[top] + 1;
            if (left == s) return dist1[left];
            queue1.push(left);
        }

        string right = rotate_right(top);
        if (!dist1.count(right)) {
            dist1[right] = dist1[top] + 1;
            if (right == s) return dist1[right];
            queue1.push(right);
        }
    }

    while (!queue2.empty()) {
        string top = queue2.front();
        queue2.pop();

        if (dist1.count(top)) return dist1[top] + dist2[top];

        string left = r_rotate_left(top);
        if (!dist2.count(left)) {
            dist2[left] = dist2[top] + 1;
            if (left == a) return dist2[left];
            queue2.push(left);
        }

        string right = r_rotate_right(top);
        if (!dist2.count(right)) {
            dist2[right] = dist2[top] + 1;
            if (right == a) return dist2[right];
            queue2.push(right);
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        for (int i = 0; i < 10; ++i) {
            char c;
            cin >> c;
            a.push_back(c);
        }
        cout << bfs() << "\n";
    }
}