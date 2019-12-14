#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int opt[201][201][201];

void print(int n, int m, int K) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < K; k++) {
                cout << opt[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int dp(int i, int j, int k, string &s, string &t) {
    if (opt[i][j][k] != -1) return opt[i][j][k];
    int n = s.length(), m = t.length();
    int ans = INT_MAX;
    if (i == n) { // t remains
        if (t[j] == '(') {
            ans = 1 + dp(i, j+1, k+1, s, t);
        }
        else if (k > 0) {
            ans = 1 + dp(i, j+1, k-1, s, t);
        }
        else {
            ans = 2 + dp(i, j+1, k, s, t);
        } 
    }
    else if (j == m) {
        if (s[i] == '(') {
            ans = 1 + dp(i+1, j, k+1, s, t);
        }
        else if (k > 0) {
            ans = 1 + dp(i+1, j, k-1, s, t);
        }
        else {
            ans = 2 + dp(i+1, j, k, s, t);
        }
    }
    else if (s[i] == t[j]) {
        if (s[i] == '(') {
            ans = 1 + dp(i+1, j+1, k+1, s, t);
        }
        else if (k > 0) {
            ans = 1 + dp(i+1, j+1, k-1, s, t);
        }
        else {
            ans = 2 + dp(i+1, j+1, k, s, t);
        }
    }
    else if (s[i] == '(') {
        ans = 1 + dp(i+1, j, k+1, s, t);
        if (k > 0) ans = min(ans, 1 + dp(i, j+1, k-1, s, t));
        else ans = min(ans, 2 + dp(i, j+1, k, s, t));
    }
    else { // s[i] == ')'
        ans = 1 + dp(i, j+1, k+1, s, t);
        if (k > 0) ans = min(ans, 1 + dp(i+1, j, k-1, s, t));
        else ans = min(ans, 2 + dp(i+1, j, k, s, t));
    }
    opt[i][j][k] = ans;
    return ans;
}

void sherlock(int x) {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length(), K = max(n, m);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= K; k++) {
                opt[i][j][k] = -1;
            }
        }
    }
    for (int k = 0; k < K; k++) {
        opt[n][m][k] = k;
    }
    // print(n+1, m+1, K+1);
    cout << dp(0, 0, 0, s, t) << endl;
    // print(n+1, m+1, K+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}