#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void sherlock(int t) {
    int r, c, K;
    cin >> r >> c >> K;
    vector<vector<int>> v(r, vector<int> (c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    // print(v);   
    vector<vector<int>> m(r, vector<int> (c));
    for (int i = 0; i < r; i++) {
        // process row;
        for (int j = 0; j < c; j++) {
            int l = 1, ma = v[i][j], mi = v[i][j];
            for (int k = j + 1; k < c; k++) {
                ma = max(ma, v[i][k]);
                mi = min(mi, v[i][k]);
                if (ma - mi > K) break;
                l++;
            }    
            m[i][j] = l;
        }
    }
    // print(m);
    // process col;
    int area = 0;
    vector<int> left(r), right(r);
    stack<int> s; // index as elem
    for (int j = 0; j < c; j++) {
        int i = 0;
        while(!s.empty()) s.pop();
        while (i < r) {
            while (!s.empty() && m[s.top()][j] >= m[i][j]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
            i++;    
        }
        while(!s.empty()) s.pop();
        i = r - 1;
        while (i >= 0) {
            while (!s.empty() && m[s.top()][j] >= m[i][j]) {
                s.pop();
            }
            right[i] = s.empty() ? r : s.top();
            s.push(i);
            i--;
        }
        for (int i = 0; i < r; i++) {
            area = max(area, m[i][j] * (right[i] - left[i] - 1));
        }
    }
    cout << "Case #" << t << ": " << area << endl;
    v.clear();
    m.clear();
    left.clear();
    right.clear();
}   

int main() {
    int t;
    cin >> t;
    for (int i = 1;i <= t; i++) {
        sherlock(i);
    }
}