#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (1LL << 60);

template <ll mx>
ll mul(ll x, ll y) {
    if (!x) {
        return 0;
    }

    if (mx / x < y) {
        return mx;
    }

    return x * y;
}

ll mpow(ll a, ll k) {
    ll ans = 1;
    while (k) {
        if (k & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        k >>= 1;
    }
    return ans;
}

void find_pfs(ll x, vector<ll> &pf) {
    ll p = 2;
    while (p * p <= x) {
        if (x % p == 0) pf.push_back(p);
        while (x % p == 0) {
            x /= p;
        }
        p++;
    }
    if (x > 1) pf.push_back(x);
}



ll onePrime(ll p, ll n) {
    ll pp = p;
    ll c = 0;
    while (pp <= n) {
        c += n / pp;
        pp = mul<INF>(pp, p);
    }
    return mpow(p, c);
}

void sherlock(int t) {
    ll x, n;
    cin >> x >> n;
    vector<ll> pf;
    find_pfs(x, pf);
    ll ans = 1;
    for (auto p : pf) {
        ans *= onePrime(p, n);
        ans %= MOD;
    }
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