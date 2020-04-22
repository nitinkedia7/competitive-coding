#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int c, vector<vector<int>> &adj, vector<int> &vis, vector<int> &color) {
    vis[u] = 1;
    color[u] = c;
    c = !c;
    for (auto v : adj[u]) {
        if (vis[v] == 0) {
            dfs(v, c, adj, vis, color);
        }    
    }
    vis[u] = 2;
}

void sherlock() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    vector<int> color(n), vis(n);
    dfs(0, 0, adj, vis, color);
    int p = 0;
    for (int i = 0; i < n; i++) {
        // cout << color[i] << " ";
        p += color[i];
    }
    // cout << endl;
    int w = p <= n - p ? 1 : 0;
    cout << min(p, n - p) << endl;
    for (int i= 0; i < n; i++) {
        if (color[i] == w) cout << i + 1 << " ";
    }
    cout << endl;
    adj.clear();
    color.clear();
    vis.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) sherlock();
    return 0;
}