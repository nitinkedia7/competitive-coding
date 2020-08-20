#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, k;
    cin >> n >> k;
    ll max_div = 1;
    for (ll d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            if (d <= k) max_div = max(max_div, d);
            if (n / d <= k) max_div = max(max_div, n / d);
        }
    }
    cout << n / max_div << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
