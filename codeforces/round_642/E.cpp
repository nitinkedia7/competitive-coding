#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N_MAX = 1e6;

int n, k;
int s[N_MAX], prefix[N_MAX], dp[N_MAX][2];

int pop_count(int l, int r) {
    if (l > r) return 0;
    return prefix[r] - (l == 0 ? 0 : prefix[l-1]);
}

void sherlock(int t) {
    cin >> n >> k;
    char x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s[i] = x - '0';
        prefix[i] = x - '0';
    }
    for (int i = 1; i < n; i++) {
        prefix[i] += prefix[i-1];
    }        
    dp[0][0] = (s[0] ? 1 : 0);
    dp[0][1] = (s[0] ? 0 : 1);
    for (int i = 1; i < n; i++) {
        dp[i][0] = (s[i] ? 1 : 0);
        dp[i][0] += min(dp[i-1][0], dp[i-1][1]);

        dp[i][1] = pop_count(0, i-1);
        if (i - k >= 0) {
            dp[i][1] = min(dp[i][1], dp[i-k][1] + pop_count(i-k+1, i-1));
        }
        dp[i][1] += (s[i] ? 0 : 1);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << prefix[i] << " "; 
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << dp[i][0] << " "; 
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << dp[i][1] << " "; 
    // }
    // cout << endl;

    cout << min(dp[n-1][1], dp[n-1][0]) << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
