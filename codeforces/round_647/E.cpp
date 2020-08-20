#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const ll INF = 1e18;

ll mul(ll x, ll y) {
    if (!x || !y) return 0;
    if (INF / x < y) {
        return INF;
    }
    return x * y;
}

ll nmpow(ll a, ll k) {
    ll ans = 1;
    while (k) {
        if (k & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        k >>= 1;
    }
    return ans;
}

ll mpow(ll a, ll k) {
    ll ans = 1;
    while (k) {
        if (k & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        k >>= 1;
    }
    return ans;
}

void sherlock(int t) {
    ll n, p;
    cin >> n >> p;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (p == 1) {
        cout << n % 2 << endl;
        return;
    }
    sort(all(v), greater<ll>());
    ll sum_mod = 0, sum_pow = 0, k = v[0];
    // cout << sum_pow << " " << sum_mod << endl;
    for (int i = 0; i < n; i++) {
        if (k > v[i]) {
            sum_pow = mul(sum_pow, nmpow(p, k - v[i]));
        }
        if (sum_pow == 0) {
            sum_pow += 1;
            sum_mod += mpow(p, v[i]);
            sum_mod %= MOD; 
        }
        else {
            sum_pow -= 1;
            sum_mod += (MOD - mpow(p, v[i]));
            sum_mod %= MOD; 
        }
        k = v[i];
        // cout << sum_pow << " " << sum_mod << endl;
    }
    cout << sum_mod << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
