#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;


void sherlock(int t) {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> f(n), g(m);
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        if (x == -1 && f[i] % p != 0) {
            x = i;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> g[i];
        if (y == -1 && g[i] % p != 0) {
            y = i;
        }
    }
    cout << x + y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}