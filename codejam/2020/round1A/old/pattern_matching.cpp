#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<vector<string>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
} 

// handle a**b
void split(string &p, vector<string> &v) {
    int i = 0, n = p.length();
    string s;
    while (i < n) {
        s.clear();
        while (p[i] != '*' && i < n) {
            s += p[i];
            i++;
        }
        v.push_back(s);
        i++;
    }
    while (v.size() < 50) {
        v.push_back("#");
    }
}

bool is_prefix(string &a, string &b) {
    if (a.length() > b.length()) return false;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void sherlock(int t) {
    int n;
    cin >> n;
    string p;
    vector<vector<string>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> p;
        split(p, v[i]);
    }
    print(v);
    string ans;
    for (int j = 0; j < 50; j++) {
        string s;
        for (int i = 0; i < n; i++) {
            if (v[i][j].length() > s.length()) {
                s = v[i][j];
            }
        }
        bool b = true;
        for (int i = 0; i < n; i++) {
            b = b && is_prefix(v[i][j], s);
        }
        if (b == false) {
            cout << "Case #" << t << ": *" << endl;
            return;        
        }
        ans += s;
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] != '#') cout << ans[i];
    }
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