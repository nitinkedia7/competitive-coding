#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll x, y, n;
    cin >> x >> y >> n;
    ll q = n / x;
    if (q * x + y <= n) {
        cout << q * x + y << endl;
    }
    else {
        assert(q > 0);
        cout << (q - 1) * x + y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
