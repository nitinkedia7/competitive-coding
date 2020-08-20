#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<ll> &v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll query(int l, int r, int n, vector<ll> &v) {
    l += n;
    r += n;
    ll g = v[l];
    while (l < r) {
        if (l & 1) {
            g = gcd(g, v[l++]);
            l++;
        }
        if (r & 1) {
            g = gcd(g, v[--r]);
        }
        l >>= 1;
        r >>= 1;
    }
    return g;
}

void update(int l, ll val, int n, vector<ll> &v) {
    l += n;
    v[l] = val;
    l >>= 1;
    while (l > 0) {
        v[l] = gcd(v[l << 1], v[(l << 1) | 1]);
        l >>= 1;
    }
}

ll gcd_sum(int l, int n, int nz, vector<ll> &v) {
    // for (int i = 0; i <= l; i++) {
    //     cout << v[i+n] << " ";
    // }
    // cout << endl;
    int s = l, e = nz;
    ll g = v[nz + n];
    ll ans = 0;
    while (e >= 0) {
        int p_e = e;
        int l = 0, r = e, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (query(mid, s+1, n, v) < g) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        } 
        e = l - 1;
        // cout << l << " " << p_e << " " << s << " " << g << endl;
        ans += ((p_e - e) * g) % MOD;
        ans %= MOD;
        g = query(e, s+1, n, v);
    }
    // cout << ans << endl << endl;
    return ans;
}

void dfs(int u, int p, vector<vector<int>> &adj, vector<ll> &a, vector<ll> &seg, int l, int n, int nz, ll &ans) {
    if (a[u] != 0) {
        nz = l;
    }
    update(l, a[u], n, seg);
    ans += gcd_sum(l, n, nz, seg);
    ans %= MOD;
    if (adj[u].size() == 1 && adj[u][0] == p) {
        update(l, 0, n, seg);
        return;
    }   
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj, a, seg, l+1, n, nz, ans);
        }
    }
    update(l, 0, n, seg);
    return;
} 

void sherlock(int t) {
    int n;
    cin >> n; 
    vector<ll> a(n), path;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    vector<ll> seg(2 * n, 0);
    dfs(0, -1, adj, a, seg, 0, n, 0, ans);
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
