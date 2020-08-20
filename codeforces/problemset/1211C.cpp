#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1e9 + 7;
const int MAXN = 2 * 1e5;
 
ll n, k;
ll a[MAXN], b[MAXN], c[MAXN];

void sherlock(int t) {
    cin >> n >> k;
    ll sa = 0, sb = 0, cost = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        sa += a[i];
        sb += b[i];
    }
    if (k < sa || k > sb) {
        cout << -1 << endl;
        return;
    }
    k -= sa;
    vector<pair<ll,ll>> v(n);
    for (int i = 0; i < n; i++) {
        cost += a[i] * c[i];
        v[i] = {c[i], b[i] - a[i]};
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        ll amt = min(v[i].second, k);
        k -= amt;
        cost += v[i].first * amt;
    }
    cout << cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
