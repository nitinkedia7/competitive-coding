#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int make(ll &n) {
    ll l = 0;
    ll r = 0;
    while (r <= n) {
        l++;
        r += 3 * l - 1;
    }
    // r > n;
    r -= 3 * l - 1;
    n -= r;
    l--;
    // cout << l << " " << r << endl;
    return l > 0;
}

void sherlock(int t) {
    ll n;
    cin >> n;
    int c = 0;
    while (make(n)) {
        c++;
    }
    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
