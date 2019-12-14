#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int opt[201][201][201];
int par[201][201][201];

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

void findstring(int n, int m, string &s, string &t) {
    int i = 0, j = 0, k = 0, p = par[i][j][k];
    string ans;
    int ni, nj, c;
    while (p != -1) {
        switch (p) {
            case 1:
                ans += ')';
                k--;
                break;
            case 2:
                ni = i < n ? i + 1 : i;
                nj = j < m ? j + 1 : j;
                c = i == n ? t[j] : s[i];
                if (c == '(') {
                    ans += '(';
                    k++;
                }
                else if (k > 0) {
                    ans += ')';
                    k--;
                }
                else {
                    ans += "()";
                }
                i = ni;
                j = nj;
                break;
            case 3:
                ans += '(';
                i++;
                k++;
                break;
            case 4:
                ans += ')';
                j++;
                k--;
                break;
            case 5:
                ans += "()";
                j++;
                break;
            case 6:
                ans += '(';
                j++;
                k++;
                break;
            case 7:
                ans += ')';
                i++;
                k--;
                break;
            case 8:
                ans += "()";
                i++;
                break;
            default:
                assert(false);
        }
        p = par[i][j][k];
    }
    cout << ans << endl;
}

int dp(int i, int j, int k, string &s, string &t) {
    if (opt[i][j][k] != -1) return opt[i][j][k];
    
    int n = s.length(), m = t.length();
    int ans = INT_MAX;
    if (i == n && j == m && k > 0) {
        ans = 1 + dp(i, j, k - 1, s, t);
        par[i][j][k] = 1;
    }
    else if (i == n || j == m || s[i] == t[j]) {
        int ni = i < n ? i + 1 : i;
        int nj = j < m ? j + 1 : j;
        char c = i == n ? t[j] : s[i];
        if (c == '(') {
            ans = 1 + dp(ni, nj, k+1, s, t);
        }
        else if (k > 0) {
            ans = 1 + dp(ni, nj, k-1, s, t);
        }
        else {
            ans = 2 + dp(ni, nj, k, s, t);
        }
        par[i][j][k] = 2;
    }
    else if (s[i] == '(') {
        ans = 1 + dp(i+1, j, k+1, s, t);
        par[i][j][k] = 3;
        if (k > 0) {
            int x = 1 + dp(i, j+1, k-1, s, t);
            if (x < ans) {
                ans = x;
                par[i][j][k] = 4;
            }
        }
        else {
            int x = 2 + dp(i, j+1, k, s, t);
            if (x < ans) {
                ans = x;
                par[i][j][k] = 5;
            }
        }
    }
    else { // s[i] == ')'
        ans = 1 + dp(i, j+1, k+1, s, t);
        par[i][j][k] = 6;
        if (k > 0) {
            int x = 1 + dp(i+1, j, k-1, s, t);
            if (x < ans) {
                ans = x;
                par[i][j][k] = 7;
            }
        }
        else {
            int x = 2 + dp(i+1, j, k, s, t);
            if (x < ans) {
                ans = x;
                par[i][j][k] = 8;
            }
        }
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
                par[i][j][k] = -1;
            }
        }
    }
    opt[n][m][0] = 0;
    dp(0, 0, 0, s, t);
    findstring(n, m, s, t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}