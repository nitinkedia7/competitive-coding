#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void bfs(int u, vector<vector<int>> &adj, vector<int> &dist) {
    int n = adj.size();
    vector<int> vis(n);
    queue<pair<int,int>> q;
    q.push({u, 0});
    vis[u] = 1; 
    while (!q.empty()) {
        u = q.front().first;
        dist[u] = q.front().second;
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                q.push({v, dist[u] + 1});
                vis[v] = 1;
            }
        }
    }
    return;
}

void sherlock(int t) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--;
    b--;
    c--;
    vector<ll> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    for (int i = 1; i < m; i++) {
        p[i] += p[i-1];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (a == b && b == c) {
        cout << 0 << endl;
        return;
    }
    if (a == b || b == c) {
        int x = min(a,min(b, c)), y = max(a,max(b, c));
        vector<int> d(n);
        bfs(x, adj, d);
        cout << p[d[y]-1] << endl;
        return;
    }
    if (a == c) {
        vector<int> d(n);
        bfs(a, adj, d);
        cout << 2 * p[d[b]-1] << endl;
        return;
    }

    vector<int> da(n), db(n), dc(n);
    bfs(a, adj, da);
    bfs(b, adj, db);
    bfs(c, adj, dc);

    ll minc = LLONG_MAX, mi;
    for (int i = 0; i < n; i++) {
        int x = da[i] + db[i] + dc[i];
        if (x > m) continue; 
        ll canc = p[x-1];
        if (db[i] > 0) canc += p[db[i] - 1];
        if (canc < minc) {
            minc = canc;
            mi = i;
        }
    }
    // cout << mi << " ";
    cout << minc << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}