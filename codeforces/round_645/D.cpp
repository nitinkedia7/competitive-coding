#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

ll sum(ll d, ll x) {
    if (x > d) {
        cout << x << " " << d << endl;
    }
    assert(x <= d);
    ll ans = (d * (d + 1)) / 2;
    ll y = d - x;
    ans -= (y * (y + 1)) / 2;
    return ans;
}

ll psum(vector<ll> &p, int l, int r) {
    return p[r] - (l == 0 ? 0 : p[l-1]);
}

void sherlock(int t) {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n), p(2 * n), p2(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p[i] = v[i];
        p[i+n] = v[i];
        p2[i] = (v[i] * (v[i] + 1)) / 2; 
        p2[i+n] = (v[i] * (v[i] + 1)) / 2; 

    }    
    for (int i = 1; i < 2 * n; i++) {
        p[i] += p[i-1];
        p2[i] += p2[i-1];
    }
    ll h = 0;
    for (int i = 0; i < n; i++) {
        if (x <= v[i]) {
            h = max(h, sum(v[i], x)); 
        }
    }
    for (int i = 1; i <= n; i++) {
        // continue;
        int l = i, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (psum(p, i, mid) < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        ll y = x - psum(p, i, l);
        ll d1 = v[i-1], d2 = v[(i+1) % n];
        if (y > d1 + d2) continue;
        ll extra = 0;
        if (y <= d1) {
            extra = sum(d1, y);
        }
        else if (y <= d2) {
            extra = sum(d2, y);
        }
        else {
            y -= d2;
            extra = sum(d2, d2);
            extra += sum(d1, y);
            ll extra2 = sum(d1, d1);
            extra2 += sum(d2, y + d2 - d1);
            if (extra2 > extra) extra2 = extra;
        }
        // cout << extra << endl;
        h = max(h, extra + psum(p2, i, l));
    }
    for (int i = 1; i <= n; i++) {
        ll d1 = v[i-1], d2 = v[(i + 1) % n];
        if (x > d1 + d2) continue;
        ll extra = 0, y = x;
        // cout << y << " " << d1 << " " << d2 << endl;
        if (y <= d1) {
            extra = sum(d1, y);
        }
        else if (y <= d2) {
            extra = sum(d2, y);
        }
        else {
            y -= d2;
            extra = sum(d2, d2);
            extra += sum(d1, y);

            ll extra2 = sum(d1, d1);
            extra2 += sum(d2, y + d2 - d1);
            if (extra2 > extra) extra2 = extra;
        }
        h = max(h, extra);
    }
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
