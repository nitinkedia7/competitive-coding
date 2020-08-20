#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 998244353;

ll A(int n, vector<int> &v, vector<ll> &fac) {
    sort(all(v));
    int c = 1;
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]) c++;
        else {
            ans *= fac[c];
            ans %= MOD;
            c = 1;
        }
    }
    ans *= fac[c];
    ans %= MOD;
    return ans;
}

ll AnB(int n, vector<pair<int,int>> &v, vector<ll> &fac) {
    sort(all(v));
    for (int i = 1; i < n; i++) {
        if (!(v[i].first >= v[i-1].first && v[i].second >= v[i-1].second)) return 0;
    }
    int c = 1;
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]) c++;
        else {
            ans *= fac[c];
            ans %= MOD;
            c = 1;
        }
    }
    ans *= fac[c];
    ans %= MOD;
    return ans;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        v[i] = {a[i], b[i]};
    } 
    vector<ll> fac(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i-1] * i) % MOD;
    }
    ll a1 = A(n, a, fac), b1 = A(n, b, fac), anb = AnB(n, v, fac);
    // cout << a1 << " " << b1 << " " << anb << endl;
    a1 = MOD - 1 - a1;
    b1 = MOD - 1 - b1;
    ll ans = fac[n];
    ans += anb;
    ans %= MOD;
    ans += 2;
    ans %= MOD;
    ans += a1;
    ans %= MOD;
    ans += b1;
    ans %= MOD;
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
