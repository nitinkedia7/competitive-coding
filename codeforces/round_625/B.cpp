#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    map<int,ll> mp;
    int b;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        mp[i - b] += b;
    }
    ll ans = 0;
    for (auto p : mp) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
