#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> v(n+1), dp(n+1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = n; i > 0; i--) {
        int x = 2 * i;
        while (x <= n) {
            if (v[i] < v[x]) {
                dp[i] = max(dp[i], 1 + dp[x]);
            }
            x += i;
        }
    }   
    cout << *max_element(dp.begin() + 1, dp.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
