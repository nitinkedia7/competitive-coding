#include <bits/stdc++.h>
using namespace std;

const int N = 201, INF = INT_MAX;
int opt[N][N][N];
tuple<int,int,int> pnext[N][N][N];
string s, t;
int n, m;

int dp(int i, int j, int k) {
    assert(i >= 0 && i <= n);
    assert(j >= 0 && j <= m);
    assert(k >= 0);
    // assert(k <= max(n, m));

    if (opt[i][j][k] != INF) return opt[i][j][k];
    for (char c = '('; c <= ')'; c++) {
        int ni = (i < n && s[i] == c ? i + 1 : i);
        int nj = (j < m && t[j] == c ? j + 1 : j);
        int nk = (c == '(' ? k + 1 : k - 1);
        if (nk < 0) {
            cout << nk << endl;
            continue;  
        } 
        int cand = 1 + dp(ni, nj, nk);
        if (cand < opt[i][j][k]) {
            opt[i][j][k] = cand;
            // pnext[i][j][k] = {ni, nj, nk};
        } 
    }
    return opt[i][j][k];
}

int main() {
    cin >> s >> t;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                opt[i][j][k] = INF;
            }
        }
    }
    n = s.length(), m = t.length();
    opt[n][m][0] = 0; 
    // dp(0, 0, 0);
    cout << dp(0, 0, 0) << endl;
    return 0;
    string ans;
    int i = 0, j = 0, k = 0;
    while (!(i == n && j == m && k == 0)) {
        int ci = i, cj = j, ck = k;
        i = get<0> (pnext[ci][cj][ck]);
        j = get<1> (pnext[ci][cj][ck]);
        k = get<2> (pnext[ci][cj][ck]);
        ans += (k > ck ? '(' : ')');
    } 
    cout << ans << endl;
    return 0;
}   