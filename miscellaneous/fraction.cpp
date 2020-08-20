#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

struct Frac {
    // (0, 1) denotes 0 and (1, 0) denotes infinity
    ll x, y;
    Frac(ll _x, ll _y) : x(), y() {
        ll g = gcd(_x, _y);
        x = _x / g;
        y = _y / g;
    } 
};

// auto comp_frac = [](const Frac &a, const Frac &b) -> bool {
//     return (a.x * b.y < a.x * b.y);
// };

struct comp_frac {
    bool operator() (const Frac &a, const Frac &b) const {
        return (a.x * b.y < a.x * b.y);
    }
};

map<Frac, int, comp_frac> mp;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, y;
    cin >> x >> y;
    Frac f(x, y);
    cout << f.x << " " << f.y << endl;
    // int tt;
    // cin >> tt;
    // for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
