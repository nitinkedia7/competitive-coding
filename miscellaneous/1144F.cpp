#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges(m);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n), type(n, -1);
    // bfs SOURCE 0 SINK 1
    bool yes = true;
    queue<int> q;
    q.push(0);
    type[0] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                type[v] = !type[u];
                vis[v] = 1;
                q.push(v);
            }
            else if (type[u] == type[v]) {
                yes = false;
            }
        }
        vis[u] = 2;
    } 
    if (!yes) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            u = edges[i].first;
            v = edges[i].second;
            assert(type[u] != type[v]);
            cout << type[u];
        }
        cout << endl;
    }
    return 0;
}