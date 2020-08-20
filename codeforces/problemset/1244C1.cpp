#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    for (int y = 0; y < w; y++) {
        ll rp = p - y * d;
        if (rp >= 0 && rp % w == 0) {
            ll x = rp / w;
            if (x + y <= n) {
                cout << x << " " << y << " " << n - x - y << endl;
                return;
            }
        } 
    }
    cout << -1 << endl;
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