#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void dfs(int u, int p, int d, vector<vector<int>> &adj, vector<int> &ss, set<pair<int,int>> &v, vector<int> &par, vector<int> &dist) {
    dist[u] = d;
    par[u] = p;
    if (adj[u].size() == 1 && adj[u][0] == p) {
        v.insert({-1 * d, u});
        ss[u] = 1;
        return;
    }
    ss[u] = 1;
    for (auto c : adj[u]) {
        if (c == p) continue;
        dfs(c, u, d+1, adj, ss, v, par, dist);
        ss[u] += ss[c];
    }
    return;
}

void dfs1(int u, int p, vector<vector<int>> &adj, vector<int> &type, vector<int> &s) {
    if (adj[u].size() == 1 && adj[u][0] == p) {
        s[u] = type[u];
        return;
    }
    s[u] = type[u];
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u, adj, type, s);
        s[u] += s[v];
    }
    return;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ss(n), par(n), dist(n);
    set<pair<int,int>> g;
    dfs(0, -1, 0, adj, ss, g, par, dist);
    vector<int> ss1 = ss, type(n);
    
    pair<int,int> z;
    while (k > 0) {
        z = *g.begin();
        g.erase(g.begin());
        // cout << z.second + 1 << endl;
        type[z.second] = 1;
        ss[par[z.second]] -= ss1[z.second];
        if (ss[par[z.second]] == 1) {
            g.insert({-1 * dist[par[z.second]]  + ss1[par[z.second]] - 1, par[z.second]});
            // g.push_back(par[g[i]]);
        }
        k--;
    }
    

    // print(type);
    vector<int> s(n);
    dfs1(0, -1, adj, type, s);
    // print(s);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (type[i] == 0) {
            ans += s[i];
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}