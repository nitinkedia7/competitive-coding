#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool find_path(int source, int sink, int n, vector<set<int>> &adj) {
    vector<int> parent(adj.size(), -1), vis(adj.size(), 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
                parent[v] = u;
            }
        }
    }
    if (parent[sink] == -1) return false;
    int cur = sink, par = parent[cur];
    while (par != -1) {
        adj[par].erase(cur);
        adj[cur].insert(par);
        cur = par;
        par = parent[cur];
    }
    return true;
}

int find_maximal_subset(int n, vector<vector<int>> &v, int x) {
    // Construct bipartite graph
    vector<set<int>> adj(2 * n + 2);
    int source = 2 * n, sink = 2 * n + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == x) {
                adj[i].insert(n + j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        adj[source].insert(i);
    }
    for (int j = 0; j < n; j++) {
        adj[n+j].insert(sink);
    }
    // Max flow
    int flow = 0;
    while (find_path(source, sink, n, adj)) {
        flow++;
    }
    return flow;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int mss = 0;
    for (int i = -1 * n; i <= n; i++) {
        if (i == 0) continue;
        mss += find_maximal_subset(n, v, i);
    }
    cout << "Case #" << t << ": " << n * n - mss << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
