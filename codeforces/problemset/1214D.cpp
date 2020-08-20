#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void reachable(vector<string> &v, vector<vector<bool>> &dp) {
    int n = v.size(), m = v[0].size();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#') continue;
            if (valid(i-1, j, n, m) && dp[i-1][j]) {
                dp[i][j] = 1;
            }
            if (valid(i, j-1, n, m) && dp[i][j-1]) {
                dp[i][j] = 1;
            }
        }
    }
}

void reachable_r(vector<string> &v, vector<vector<bool>> &dp) {
    int n = v.size(), m = v[0].size();
    dp[n-1][m-1] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (v[i][j] == '#') continue;
            if (valid(i+1, j, n, m) && dp[i+1][j]) {
                dp[i][j] = 1;
                continue;
            }
            if (valid(i, j+1, n, m) && dp[i][j+1]) {
                dp[i][j] = 1;
            }
        }
    }
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<bool>> dp(n, vector<bool> (m));
    vector<vector<bool>> dp_r(n, vector<bool> (m));
    reachable(v, dp);
    if (dp[n-1][m-1] == 0) {
        cout << 0 << endl;
        return;
    }
    reachable_r(v, dp_r);
    vector<int> count(n + m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] && dp_r[i][j]) {
                count[i + j]++;
            }
        }
    }
    for (int i = 1; i < n + m - 2; i++) {
        if (count[i] == 1) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
