#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll l, r, m;
    cin >> l >> r >> m;
    for (ll a = l; a <= r; a++) {
        // LEFT
        ll k = m / a, diff = m % a;
        if (k > 0 && diff <= (r - l)) {
            cout << a << " " << l + diff << " " << l << endl;
            return;
        }
        k = (m / a) + 1, diff = a - (m % a);
        if (k > 0 && diff <= r - l) {
            cout << a << " " << l << " " << l + diff << endl;
            return;
        }
    }    
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
