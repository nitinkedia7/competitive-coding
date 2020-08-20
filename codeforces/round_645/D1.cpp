#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

ll basic_sum(ll n) {
    return (n * (n + 1)) / 2;
}

ll reverse_sum(ll d, ll x) {
    assert(x <= d);
    ll ans = (d * (d + 1)) / 2;
    ll y = d - x;
    ans -= (y * (y + 1)) / 2;
    return ans;
}

ll psum(vector<ll> &p, int l, int r) {
    return p[r] - (l == 0 ? 0 : p[l-1]);
}

void func(ll n, ll x, vector<ll> &v, ll &h, bool rev) {
    vector<ll> p(2 * n), p2(2 * n);
    for (int i = 0; i < n; i++) {
        p[i + n] = p[i] = v[i];
        p2[i + n] = p2[i] = (v[i] * (v[i] + 1)) / 2; 

    }    
    for (int i = 1; i < 2 * n; i++) {
        p[i] += p[i-1];
        p2[i] += p2[i-1];
    }
    for (int i = 0; i < n; i++) {
        int l = i, r = n + i - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (psum(p, i, mid) <= x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        ll x1 = l == i ? 0 : psum(p, i, l-1);
        ll h1 = l == i ? 0 : psum(p2, i, l-1);
        if (!rev) {
            h1 += basic_sum(x - x1);
        }
        else {
            h1 += reverse_sum(v[l % n], x - x1);
        }
        // cout << i << " " << l << " " << h1 << endl;
        h = max(h, h1);
    }
}

void sherlock(int t) {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    ll h = 0;
    func(n, x, v, h, false);
    // cout << h << endl;
    reverse(all(v));
    func(n, x, v, h, true);
    cout << h << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
