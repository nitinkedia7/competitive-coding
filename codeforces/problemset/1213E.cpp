#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool check(string &ans, string &s, string &t) {
    if (ans[0] == s[0] && ans[1] == s[1]) return false;
    if (ans[1] == s[0] && ans[2] == s[1]) return false;
    if (ans[0] == t[0] && ans[1] == t[1]) return false;
    if (ans[1] == t[0] && ans[2] == t[1]) return false;
    return true;
}

void sherlock(int tc) {
    int n;
    string s, t, x;
    cin >> n >> s >> t;
    int c = 0;
    if (s[0] == s[1]) c++;
    else x = s;
    if (t[0] == t[1]) c++;
    else x = t;    
    if (c == 2) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << "abc";
        }
        cout << endl;
        return;
    }
    else if (c == 1) {
        char z;
        for (int i = 0; i < 3; i++) {
            z = 'a' + i;
            if (x[0] != z && x[1] != z) {
                break;
            }
        }
        // cout << x << " " << z << endl;
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << x[1] << x[0] << z;
        }
        cout << endl;
        return;
    }
    else {
        vector<string> ans{"abc", "acb", "bac", "bca", "cab", "cba"};
        for (int i = 0; i < 6; i++) {
            if (check(ans[i], s, t)) {
                cout << "YES" << endl;
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < n; k++) {
                        cout << ans[i][j];
                    }
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
