#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll mpow(ll a, ll k){
    ll ans = 1;
    while(k){
       if(k&1)ans = ans*a%mod;
       a = a*a%mod;
       k >>= 1;
    }
    return ans;
}


ll nCr(ll n, ll r)
{
   vector<ll> f(n + 1,1);
   for (ll i=2; i<=n;i++)
       f[i]= (f[i-1]*i) % mod;
    ll a = mpow(f[r], mod-2);
    ll b =  mpow(f[n-r], mod-2);
    ll c = f[n];
   return (c*((a * b) % mod)) % mod;
}


void sherlock(int t) {
    ll n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    ll ans = nCr(m, n-1);
    ans *= (n-2);
    ans %= mod;
    for (int i = 0; i < n-3; i++) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}