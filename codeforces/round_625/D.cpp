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

void bfs(int u, int n, vector<vector<int>> &adj, vector<int> &dist) {
    vector<int> vis(n);
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    vis[u] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }
    // print(vis);
    // print(dist);
    return;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), adjr(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }    
    int k;
    cin >> k;
    vector<int> path(k);
    for (int i = 0; i < k; i++) {
        cin >> u;
        u--;
        path[i] = u;
    }
    vector<int> dist(n);
    bfs(path[k-1], n, adjr, dist);
    // MAXIMUM
    int ans_max = 0;
    for (int i = 0; i < k-1; i++) {
        u = path[i];
        for (auto v : adj[u]) {
            if (v != path[i+1] && dist[v] + 1 == dist[u]) {
                ans_max++;
                break;
            }
        } 
    }
    // MINIMUM
    int i = 0, ans_min = 0;
    while (i < k-1) {
        int j = i+1;
        while (j < k && dist[path[j-1]] == 1 + dist[path[j]]) {
            j++;
        }
        if (j != k-1) {
            ans_min++;
            // cout << i << "," << j << endl;
        }
        i = j;
    }
    cout << ans_min-1 << " " << ans_max << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
