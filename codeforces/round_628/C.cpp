#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    int u, v;
    vector<pair<int,int>> edges;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--;
        v--;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    int a, b;
    while (!q.empty()) {
        u = q.front();
        a = u;
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }    
    fill(vis.begin(), vis.end(), 0);
    vector<int> par(n), dist(n);
    q.push(a);
    par[a] = -1;
    dist[a] = 0;
    vis[a] = 1;
    while (!q.empty()) {
        u = q.front();
        b = u;
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                q.push(v);
                par[v] = u;
                vis[v] = 1;
                dist[v] = dist[u] + 1;
            }
        }
    }
    // cout << a << " " << b << " " << dist[b] << endl;
    if (dist[b] == n-1) {
        for (int i = 0; i < n-1; i++) {
            cout << i << endl;
        }
        return;
    }
    map<pair<int,int>,int> m;
    fill(vis.begin(), vis.end(), 0);
    int p = b;
    while (p != -1) {
        vis[p] = 1;
        p = par[p];
    }
    int c;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            c = i;
            break;
        }
    }

    int cc = 3;
    for (int i = 0; i < n-1; i++) {
        u = edges[i].first;
        v = edges[i].second;
        if (u != par[v]) swap(u, v);
        if (u == a) {
            cout << 0 << endl;
        }
        else if (u == par[b] && v == b) {
            cout << 1 << endl;
        }
        else if (u == par[c] && v == c) {
            cout << 2 << endl;
        } 
        else {
            cout << cc << endl;
            cc++;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}