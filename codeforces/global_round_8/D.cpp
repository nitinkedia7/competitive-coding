#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int B_MAX = 20;

void sherlock(int t) {
    int n;
    cin >> n;
    ll x;
    vector<int> v(B_MAX, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 0; j < B_MAX; j++) {
            if (x & (1 << j)) {
                v[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        x = 0;
        for (int j = 0; j < B_MAX; j++) {
            if (i < v[j]) {
                x += (1 << j);
            }
        }
        ans += x * x;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
