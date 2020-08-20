#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans;
    if (b >= a) {
        ans = b;
    }   
    else if (d < c) {
        ans = b + c * ((a - b + c - d - 1) / (c - d));
    }
    else {
        ans = -1;
    }
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
