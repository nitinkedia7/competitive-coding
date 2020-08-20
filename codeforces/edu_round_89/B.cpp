#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int a, m, x;
    cin >> a >> x >> m;
    int l = x, r = x;
    int p, q;
    for (int i = 0; i < m; i++) {
        cin >> p >> q;
        if (r < p || q < l) {
            continue;
        }
        l = min(l, p);
        r = max(r, q);
    }    
    // cout << l << " " << r << endl;
    cout << r - l + 1  << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
