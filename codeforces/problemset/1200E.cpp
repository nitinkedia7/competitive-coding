#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void calc_lps(string &p, vector<int> &lps) {
    int m = p.length();
    lps.resize(m);
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return;
}

void merge(string &s, string &p, vector<int> &lps) {
    int n = s.length(), m = p.length();
    lps.clear();
    calc_lps(p, lps);
    int i = max(0, n - m), j = 0, x = 0;
    // cout << i << " ";
    while (i < n) {
        if (s[i] == p[j]) {
            j++;
            x = j;
            i++;
        }
        if (j == m) {
            j = lps[j-1];
        }
        else if (i < n && s[i] != p[j]) {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                x = j;
                i++;
            }
        }
    }
    // cout << s << " " << x << " " << p << endl;
    for (int j = x; j < m; j++) {
        s += p[j];
    }
    // cout << s << endl;
    return;
} 

void sherlock(int t) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    vector<int> lps;
    string s;
    for (int i = 0; i < n; i++) {
        merge(s, v[i], lps);
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
