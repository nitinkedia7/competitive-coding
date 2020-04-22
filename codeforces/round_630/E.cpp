#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll modexp(ll x, ll y) {
    if (y == 0) return 1;
    ll z = modexp(x, y/2);
    z *= z;
    z %= MOD;
    if (y % 2 == 0) return z;
    return (z * (x % MOD)) % MOD;
}

ll getE(ll x) {
    if (x % 2 == 0) return x/2 + 1;
    return (x+1) / 2;
}

void sherlock(int t) {
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll E = getE(r) - (l == 0 ? 0 : getE(l-1));
    ll O = (r - l + 1) - E;
    // cout << O << " " << E << endl;
    if ((n * m) % 2 == 1) {
        cout << modexp(O+E, n * m) << endl;
    }  
    else {
        ll f = modexp(O+E, n * m);
        ll s = modexp(abs(E-O), n * m);
        cout << (((f + s) % MOD) * modexp(2, MOD-2)) % MOD << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}