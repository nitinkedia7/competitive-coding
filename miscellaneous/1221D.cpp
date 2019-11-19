#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sherlock() {
    int n;
    cin >> n;
    vector<int> len(n), cost(n);
    for (int i = 0; i < n; i++) {
        cin >> len[i] >> cost[i];
    }
    vector<vector<ll>> dp(n, vector<ll> (3));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = i * 1LL * cost[0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            ll c = LLONG_MAX;
            for (int k = 0; k < 3; k++) {
                if (len[i-1] + k != len[i] + j) {
                    c = min(c, dp[i-1][k] + j * 1LL * cost[i]);
                }
            } 
            dp[i][j] = c;   
        }
    }
    cout <<  min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
    dp.clear();
    cost.clear();
    len.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        sherlock();
    }
}