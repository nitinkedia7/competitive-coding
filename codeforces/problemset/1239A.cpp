#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int ub = max(n, m) + 1;
    vector<ll> f(ub);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < ub; i++) {
        f[i] = (f[i-1] + f[i-2]) % MOD;
    }
    ll ans = f[n] + f[m] - 1;
    ans %= MOD;
    ans *= 2;
    ans %= MOD;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}