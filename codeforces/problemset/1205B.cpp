#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int bfs(int x, vector<set<int>> &adj) {
    int ans = INT_MAX;
    queue<int> q;
    map<int,int> dist, par;
    set<int> vis;
    q.push(x);
    dist[x] = 0;
    par[x] = -1;
    vis.insert(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (vis.find(v) == vis.end()) {
                q.push(v);
                vis.insert(v);
                dist[v] = 1 + dist[u];
                par[v] = u;
            }
            else if (par[v] != u && par[u] != v) {
                ans = min(ans, dist[u] + dist[v] + 1);
            }
        }
    }
    return ans;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    vector<vector<ll>> g(61);
    for (int i = 0; i < n; i++) {
        ll x = v[i];
        for (int j = 0; j < 61; j++) {
            if (x % 2 == 1) {
                g[j].push_back(i);
            }
            x /= 2;
        }
    }
    for (int i = 0; i < 61; i++) {
        if (g[i].size() >= 3) {
            cout << 3 << endl;
            return;
        }
    }
    // Graph has very less edges now
    vector<set<int>> adj(n);
    for (int i = 0; i < 61; i++) {
        if (g[i].size() == 2) {
            int u = g[i][0], v = g[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }
    // Run djikstra from every node
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, bfs(i, adj));
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
