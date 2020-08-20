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

void bfs(int r, int n, vector<vector<int>> &adj, vector<int> &dist) {
    vector<int> vis(n);
    queue<int> q;
    q.push(r);
    vis[r] = 1;
    dist[r] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                q.push(v);
                vis[v] = 1;
                dist[v] = 1 + dist[u];
            }
        }
    }
    return;
}
 
bool comp(pair<int,int> x, pair<int,int> y) {
    return (x.first - x.second < y.first - y.second);
}

void sherlock(int t) {
    int n, m, k;
    cin >> n >> m >> k;
    int u, v;
    vector<int> special;
    set<int> s;
    for (int i = 0; i < k; i++) {
        cin >> u;
        u--;
        special.push_back(u);
        s.insert(u);
    }
    vector<vector<int>> adj(n);
    bool done = false;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        if (s.find(u) != s.end() && s.find(v) != s.end()) {
            done = true;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    vector<int> dist_source(n), dist_sink(n);
    bfs(0, n, adj, dist_source);
    bfs(n-1, n, adj, dist_sink);
    int spl = dist_source[n-1];
    if (done) {
        cout << spl << endl;
        return;
    }
    vector<pair<int,int>> vk(k);
    for (int i = 0; i < k; i++) {
        vk[i] = {dist_source[special[i]], dist_sink[special[i]]};
    }
    sort(all(vk), comp);
    int y_max = vk[k-1].second;
    int ans = -1;
    for (int i = k-2; i >= 0; i--) {
        int d = 1 + vk[i].first + y_max;
        d = min(spl, d);
        ans = max(ans, d);
        if (vk[i].second > y_max) {
            y_max = vk[i].second;
        }
    }
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
