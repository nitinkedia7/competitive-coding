#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

string get(string &s) {
    string p;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*' && i > 0 && s[i-1] == '*') continue;
        p += s[i];
    }
    return p;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<string> v(n);
    string p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        p += '#';
        v[i] = get(p);
    }
    vector<int> pos(n);
    vector<vector<int>> nex(n, vector<int> (100, INT_MAX));
    for (int i = 0; i < n; i++) {
        int ls = v[i].size() - 2;
        for (int j = v[i].size() - 2; j >= 0; j--) {
            nex[i][j] = ls;
            if (v[i][j] == '*') ls = j;
        }
    }
    // cout << v[0] << endl;
    // cout << v[1] << endl;
    // print2d(nex);
    // cout << endl;
    // return;
    string ans;
    while (1) {
        // all *
        // print(pos);
        bool alldone = true;
        for (int i = 0; i < n; i++) {
            alldone = alldone && (pos[i] == v[i].size());
        }
        if (alldone) break;
        bool allstar = true;
        for (int i = 0; i < n; i++) {
            allstar = allstar && (pos[i] < v[i].length() && v[i][pos[i]] == '*');
        }
        if (allstar) {
            // cout << "1 ";
            int maxl = -1;
            char c;
            for (int i = 0; i < n; i++) {
                if (nex[i][pos[i]] - pos[i] > maxl) {
                    maxl = nex[i][pos[i]] - pos[i];
                    c = v[i][pos[i] + 1];
                } 
            }
            ans.push_back(c);
            for (int i = 0; i < n; i++) {
                if (nex[i][pos[i]] - pos[i] == maxl && c == v[i][pos[i]+1]) {
                    pos[i] += 2;
                }
            }
        }
        else { // exit, contradicting, forward
            // cout << "2 ";
            char c;
            bool done = false;
            for (int i = 0; i < n; i++) {
                if (pos[i] == v[i].size()) {
                    cout << "Case #" << t << ": *" << endl;
                    return; 
                }
                if (v[i][pos[i]] != '*') {
                    if (done && c != v[i][pos[i]]) {
                        cout << "Case #" << t << ": *" << endl;
                        return;
                    }
                    done = true;
                    c = v[i][pos[i]];
                }
            }
            ans += c;
            for (int i = 0; i < n; i++) {
                if (c == v[i][pos[i]]) {
                    pos[i]++;
                }
                else if (v[i][pos[i]] == '*' && v[i][pos[i] + 1] == c) {
                    pos[i] += 2;
                }
            }
        }
        // cout << ans << endl;
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < ans.length() - 1; i++) cout << ans[i];
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}