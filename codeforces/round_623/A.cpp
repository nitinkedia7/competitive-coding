#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll ans = 0;
    ans = max(ans, y * a);
    ans = max(ans, (b - y - 1) * a);
    ans = max(ans, x * b);
    ans = max(ans, (a - x - 1) * b);
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
