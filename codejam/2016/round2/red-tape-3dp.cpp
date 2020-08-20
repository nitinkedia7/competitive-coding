#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<ld> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // 3D dp
    ld dp[n+1][n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int y = 0; y <= n; y++) {
            for (int z = 0; z <= n; z++) {
                dp[i][y][z] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int y = 0; y <= n; y++) {
            for (int z = 0; z <= n; z++) {
                if (z > 0) dp[i][y][z] = dp[i-1][y][z-1];
                ld x = dp[i-1][y][z] * (1 - v[i-1]);
                if (y > 0) x += dp[i-1][y-1][z] * v[i-1];
                dp[i][y][z] = max(x, dp[i][y][z]);
            }
        }
    }
    cout.precision(3);
    for (int i = 0; i <= n; i++) {
        for (int y = 0; y <= n; y++) {
            for (int z = 0; z <= n; z++) {
                cout << dp[i][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Case #" << t << ": " << fixed << dp[n][k/2][n - k] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
