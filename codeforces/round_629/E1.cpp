#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll N = 2 * 10e5;

vector<int> tin(N), tout(N), parent(N), dist(N);

void dfs(int u, int p, int &t, int d, vector<vector<int>> &adj) {
    parent[u] = p;
    dist[u] = d;
    tin[u] = t++;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, t, d+1, adj);
    }
    tout[u] = t++;
}

void watson() {
    int k, u;
    cin >> k;
    vector<int> v(k);
    int fv = -1;
    for (int j = 0; j < k; j++) {
        cin >> u;
        u--;
        v[j] = u;
        if (fv == -1 || dist[fv] < dist[u]) fv = u;
    }
    fv = (fv == 0 ? 0 : parent[fv]);
    for (int j = 0; j < k; j++) {
        int p = (v[j] == 0 ? 0 : parent[v[j]]);
        if (!(tin[p] <= tin[fv] && tout[fv] <= tout[p])) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int T = 0;
    dfs(0, -1, T, 0, adj);
    for (int i = 0; i < m; i++) {
        watson();        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}