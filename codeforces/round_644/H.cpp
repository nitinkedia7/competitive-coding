#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<ll> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

ll get_less_equal(ll x, int n, vector<ll> &v, vector<ll> &c) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] > x) break;
    }
    ll base = (i > 0 ? c[i-1] : 1);
    base += x - (i > 0 ? v[i-1] : 0);
    return base;
}

ll get_ll(int m, string &s) {
    ll x = 0, p = 1;
    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == '1') {
            x += p;
        }
        p *= 2;
    }
    return x;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    string s;
    vector<ll> v(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        v[i] = get_ll(m, s);
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        c[i] = (v[i] + 1) - (i + 1);
    }
    // print(v);
    // print(c);
    // cout << get_less_equal(5, n, v, c) << endl; 
    ll p2m = 1;
    for (int i = 0; i < m; i++) {
        p2m *= 2;
    }
    if (p2m == n) {
        for (int i = 0; i < m; i++) {
            cout << 0;
        }
        cout << endl;
        return;
    }
    ll tx = (p2m - n - 1) / 2;
    tx++;
    // cout << tx << endl;
    ll l = 0, r = p2m - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        ll less_equal = get_less_equal(mid, n, v, c);
        if (less_equal < tx) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    // cout << l << endl;
    string ans;
    for (int i = 0; i < m; i++) {
        ans += ('0' + (l % 2));
        l /= 2;
    }
    reverse(all(ans));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
