#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const string p = "abacaba";
const int l = 7;

bool check(int n, string s, int st, string &ans) {
    bool f = true;
    for (int i = 0; i < l; i++) {
        if (s[st + i] == '?') {
            s[st + i] = p[i];
        }
        else if (s[st + i] == p[i]) {
            continue;
        }
        else {
            f = false;
            break;
        }
    }
    if (!f) return false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') s[i] = 'z';
    }
    int count = 0;
    for (int i = 0; i <= n - l; i++) {
        bool match = true;
        for (int j = 0; j < l; j++) {
            if (s[i + j] != p[j]) {
                match = false;
                break;
            } 
        }
        if (match) {
            count++;
        }
        if (count > 1) break;
    }
    if (count == 1) ans = s;
    return (count == 1);
}

void sherlock(int t) {
    int n;
    string s, ans;
    cin >> n >> s;    
    bool f = false;
    for (int i = 0; i <= n - l; i++) {
        f = f || check(n, s, i, ans);
        if (f) {
            cout << "Yes" << endl << ans << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
