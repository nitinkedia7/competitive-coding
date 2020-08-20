#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            cout << 1 << endl;
            return;
        }
    }
    if (x <= 2 * v[n-1]) {
        cout << 2 << endl;
    }
    else {
        cout << (x + v[n-1] - 1) / v[n-1] << endl;
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
