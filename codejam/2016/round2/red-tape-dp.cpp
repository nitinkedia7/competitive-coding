#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;

ld get_tie_prob(int n, int k, vector<ld> &prob) {
    // 2D dp
    vector<vector<ld>> dp(k + 1, vector<ld> (k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (j > 0) {
                dp[i][j] += dp[i-1][j-1] * prob[i-1];
            }
            dp[i][j] += dp[i-1][j] * (1 - prob[i-1]);
        }
    }
    return dp[k][k / 2];
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<ld> v(n), prob;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    ld max_tie_prob = 0;
    for (int m = 0; m <= k; m++) {
        prob.clear();
        for (int i = 0; i < m; i++) {
            prob.push_back(v[i]);
        }
        for (int i = n + m - k; i < n; i++) {
            prob.push_back(v[i]);
        }
        max_tie_prob = max(max_tie_prob, get_tie_prob(n, k, prob));
    }
    cout.precision(10);
    cout << "Case #" << t << ": " << fixed << max_tie_prob << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
