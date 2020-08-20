#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void dfs(int u, int p, int d, vector<vector<int>> &adj, vector<int> &vis, vector<int> &odd, vector<int> &even, vector<int> &par, vector<int> &cycle) {
    vis[u] = 1;
    par[u] = p;
    if (d % 2) odd.push_back(u);
    else even.push_back(u);
    if ((int) adj[u].size() == 0 || (adj[u].size() == 1 && adj[u][0] == p)) {
        vis[u] = 2;
        return;
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (vis[v] == 0) {
            dfs(v, u, d+1, adj, vis, odd, even, par, cycle);
        }
        else if ((int) cycle.size() == 0) {
            int x = u;
            while (x != v) {
                cycle.push_back(x);
                x = par[x];
            }
            cycle.push_back(v);
        }
    }
    vis[u] = 2;
    return;
}

void sherlock(int t) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        if (u >= k || v >= k) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n), par(n), odd, even, cycle, ans;
    for (int u = 0; u < k; u++) {
        if (vis[u] == 0) {
            // cout << u << endl;
            odd.clear();
            even.clear();
            dfs(u, -1, 0, adj, vis, odd, even, par, cycle);
            // print(vis);
            if (cycle.size() > 0) {
                cout << 2 << endl << cycle.size() << endl;
                for (auto x : cycle) {
                    cout << x + 1 << " ";
                }
                cout << endl;
                return;
            }
            if (odd.size() > even.size()) {
                for (auto x : odd) ans.push_back(x);
            }
            else {
                for (auto x : even) ans.push_back(x);
            }
        }
    }
    cout << 1 << endl;
    int todo = (k + 1) / 2;
    for (int i = 0; i < todo; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
