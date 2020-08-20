#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;

ll gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

ll find(ll b, ll d, ll r) {
    // find x in [0, r]
    ll x = r / d;
    // cout << x << endl;
    ll ans = x * b;
    ans += min(b, (r - x * d + 1));
    return ans;
}


void sherlock(int t) {
    ll a, b, q;
    cin >> a >> b >> q;
    if (a > b) swap(a, b);

    ll g = gcd(a, b);
    ll d = (b / g) * a;
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        cout << (r - l + 1) - (find(b, d, r) - find(b, d, l-1)) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}