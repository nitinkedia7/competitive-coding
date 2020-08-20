#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int R_MAX = 500, B_MAX = 500, N_MAX = 250;

int n;
int dp[N_MAX][R_MAX + 1][B_MAX + 1];

void sherlock(int t) {
    int r, b;
    cin >> r >> b;
    cout << "Case #" << t << ": " << dp[n][r][b] - 1 << endl;
}

void police() {
    // Build v
    vector<pair<int,int>> v;
    for (int i = 0; i <= R_MAX; i++) {
        for (int j = 0; j <= B_MAX; j++) {
            ll R = (j+1) * ((i * 1LL * (i + 1)) / 2);
            ll B = (i+1) * ((j * 1LL * (j + 1)) / 2);
            if (R <= R_MAX && B <= B_MAX) {
                v.push_back({i, j});
            }
        }
    }
    // make DP
    memset(dp, 0, sizeof(dp));
    n = v.size();
    // for (int r = 0; r <= R_MAX; r++) {
    //     for (int b = 0; b <= B_MAX; b++) {
    //         dp[0][r][b] = 0;
    //     }
    // } 
    for (int i = 1; i <= n; i++) {
        for (int r = 0; r <= R_MAX; r++) {
            for (int b = 0; b <= B_MAX; b++) {
                int x = dp[i-1][r][b];
                if (v[i-1].first <= r && v[i-1].second <= b) {
                    x = max(x, 1 + dp[i-1][r - v[i-1].first][b - v[i-1].second]);
                }
                dp[i][r][b] = x;
            }
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    police();
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
