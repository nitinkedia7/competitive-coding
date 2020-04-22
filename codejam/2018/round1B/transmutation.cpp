#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF2 = (1ll << 60);
const ll MINF2 = -1 * INF2;

template <ll mx>
ll add(ll x, ll y) {
    return min(mx, x + y);
}

template <ll mx>
ll mul(ll x, ll y) {
    if (!x) {
        return 0;
    }

    if (mx / x < y) {
        return mx;
    }

    return x * y;
}

bool can_make(ll x, vector<vector<ll>> r, vector<ll> g) {
    int m = g.size();
    g[0] -= x;
    while (1) {
        int i;
        for (i = 0; i < m; i++) {
            if (g[i] < 0) break;
        }
        if (i == m) return true;
        if (r[i][i] != 0) return false;
        for (int j = 0; j < m; j++) {
            g[j] = add<INF2>(mul<INF2>(r[i][j], g[i]), g[j]);
            if (g[j] == MINF2) return false;
            // g[j] = add(g[j], mul(r[i][j], g[i]));
            // g[j] += r[i][j] * g[i];
        }
        g[i] = 0;
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            if (r[j][i] == 0) continue;
            ll y = r[j][i];
            r[j][i] = 0;
            for (int k = 0; k < m; k++) {
                r[j][k] = add<INF2>(mul<INF2>(r[i][k], y), r[j][k]);
                if (r[j][k] == INF2) return false;

                // r[j][k] = add(r[j][k], mul(y, r[i][k]));
                // r[j][k] += y * r[i][k];
            }
        }
    }
}

void sherlock(int t) {
    // cout << INF2 << " " << MINF2 << endl;
    int m;
    cin >> m;
    vector<vector<ll>> r(m, vector<ll> (m, 0LL));
    int r1, r2;
    for (int i = 0; i < m; i++) {
        cin >> r1 >> r2;
        r[i][r1-1] = 1;
        r[i][r2-1] = 1;
    }
    vector<ll> g(m, 0LL);
    ll lb = 0, ub = 0;
    for (int i = 0; i < m; i++) {
        cin >> g[i];
        ub += g[i];
    }
    lb = g[0];
    while (lb <= ub) {
        ll mid = (lb + ub) / 2;
        if (can_make(mid, r, g)) {
            lb = mid + 1;
        }
        else ub = mid - 1;
    }
    cout << "Case #" << t << ": " << lb-1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}