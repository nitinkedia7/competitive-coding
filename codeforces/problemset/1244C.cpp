#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e13;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll g = gcd(b % a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return g;
}

ll find_largest(ll B, ll y1) {
    ll l = -1 * INF, r = INF;
    while (l <= r) {
        ll mid = (l+r) / 2;
        if (B * mid <= y1) {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    // cout << l-1 << " " << B << " " << y1 << endl;
    return l-1;
}

ll find_smallest(ll A, ll x1) {
    // smallest number st. r * A >= x1
    ll l = -1 * INF, r = INF;
    while (l <= r) {
        ll mid = (l+r) / 2;
        if (mid * A < x1) {
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }
    // cout << l << " " << A << " " << x1 << endl;
    return l;
}

void sherlock(int t) {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll x1, y1;
    ll g = gcd(d, w, y1, x1);
    if (p % g != 0) {
        cout << -1 << endl;
        return;
    }
    cout << g << " " << x1 << " " << y1 << endl;
    // {
    //     // make both positive/0
    //     ll A = d / g, B = w / g;
    //     ll lb = find_smallest(B, -1 * y1);
    //     ll ub = find_largest(A, x1);
    //     if (lb <= ub) {
    //         x1 -= lb * A;
    //         y1 += lb * B;
    //     }
    //     else {
    //         cout << -11 << endl;
    //         return;
    //     }
    // }
    // cout << g << " " << x1 << " " << y1 << endl;

    x1 *= (p / g);
    y1 *= (p / g);
    ll A = d / g, B = w / g;
    ll lb = find_smallest(B, -1 * y1);
    ll ub = min(find_largest(A, x1), find_largest(B-A, n-x1-y1));
    // cout << lb << " " << ub << endl;
    if (lb <= ub) {
        x1 -= lb * A;
        y1 += lb * B;
        cout << x1 << " " << y1 << " " << n - x1 - y1 << endl;  
    }
    else {
        cout << -1 << endl;
    }
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