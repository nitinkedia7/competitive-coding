#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, k;
    cin >> n >> k;
    ll x;
    map<ll,ll> mp; // mod -> count
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x % k]++;
    }
    ll ans = 0;
    for (auto p : mp) {
        ll m = p.first, c = p.second;
        if (m == 0) continue;
        ans = max(ans, (k - m) + (c - 1) * k + 1);
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
