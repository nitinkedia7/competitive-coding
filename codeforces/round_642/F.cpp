#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N_MAX = 100;

int n, m;
ll v[N_MAX][N_MAX], dp[N_MAX][N_MAX];

ll func(ll k) {
    if (k > v[0][0]) return LLONG_MAX;
    dp[0][0] = v[0][0] - k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            ll h = i + j + k;
            dp[i][j] = LLONG_MAX;
            if (i > 0 && dp[i-1][j] != LLONG_MAX && h <= v[i][j]) {
                dp[i][j] = dp[i-1][j] + (v[i][j] - h);
            }
            if (j > 0 && dp[i][j-1] != LLONG_MAX && h <= v[i][j]) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + (v[i][j] - h));
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return dp[n-1][m-1];
}

void sherlock(int t) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    } 
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll k = v[i][j] - i - j;
            ans = min(ans, func(k));
        }
    } 
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
