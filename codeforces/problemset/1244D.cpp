#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int is_linear(int n, vector<vector<int>> &adj, vector<int> &path) {
    int u, a, b;
    queue<int> q;
    vector<int> vis(n);
    q.push(0);
    vis[0] = 1;

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
    vector<int> dist(n), parent(n);
    fill(vis.begin(), vis.end(), 0);
    q.push(a);
    dist[a] = 0;
    vis[a] = 1;
    parent[a] = -1;
    while (!q.empty()) {
        u = q.front();
        b = u;
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                q.push(v);
                dist[v] = dist[u] + 1;
                vis[v] = 1;
                parent[v] = u;
            }
        } 
    }
    int p = b;
    while (p != -1) {
        path.push_back(p);
        p = parent[p];
    }
    if (dist[b] == n-1) return b;
    return -1;
}

void color(ll &cost, int i, vector<int> &c, vector<int> &path, vector<ll> &c1, vector<ll> &c2, vector<ll> &c3) {
    if (i == path.size()) return;
    int x = 0;
    x |= c[i-1];
    x |= c[i-2];
    if (x == 3) {
        c[i] = 4;
        cost += c3[path[i]];
    }
    else if (x == 5) {
        c[i] = 2;
        cost += c2[path[i]];
    }
    else if (x == 6) {
        c[i] = 1;
        cost += c1[path[i]];
    }
    else {
        assert(false);
    }
    color(cost, i+1, c, path, c1, c2, c3);
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> c1(n), c2(n), c3(n);
    for (int i = 0; i < n; i++) {
        cin >> c1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c2[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c3[i];
    }
    // tree should be linear
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> path;
    int r = is_linear(n, adj, path);
    if (r == -1) {
        cout << -1 << endl;
        return;
    }
    assert(path.size() == n);
    // for (int i = 0; i < n; i++) {
    //     cout << path[i] << " ";
    // }
    // cout << endl;
    vector<int> c(n), ans;
    ll mincost = LLONG_MAX;
    c[0] = 1;
    c[1] = 2;
    ll cost = c1[path[0]] + c2[path[1]];
    color(cost, 2, c, path, c1, c2, c3);
    if (cost < mincost) {
        mincost = cost;
        ans = c;
    }

    c[0] = 2;
    c[1] = 1;
    cost = c2[path[0]] + c1[path[1]];
    color(cost, 2, c, path, c1, c2, c3);
    if (cost < mincost) {
        mincost = cost;
        ans = c;
    }

    c[0] = 2;
    c[1] = 4;
    cost = c2[path[0]] + c3[path[1]];
    color(cost, 2, c, path, c1, c2, c3);
    if (cost < mincost) {
        mincost = cost;
        ans = c;
    }

    c[0] = 4;
    c[1] = 2;
    cost = c3[path[0]] + c2[path[1]];
    color(cost, 2, c, path, c1, c2, c3);
    if (cost < mincost) {
        mincost = cost;
        ans = c;
    }

    c[0] = 1;
    c[1] = 4;
    cost = c1[path[0]] + c3[path[1]];
    color(cost, 2, c, path, c1, c2, c3);
    if (cost < mincost) {
        mincost = cost;
        ans = c;
    }

    c[0] = 4;
    c[1] = 1;
    cost = c3[path[0]] + c1[path[1]];
    color(cost, 2, c, path, c1, c2, c3);
    if (cost < mincost) {
        mincost = cost;
        ans = c;
    }

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        f[path[i]] = ans[i];
    }
    cout << mincost << endl;
    for (int i = 0; i < n; i++) {
        if (f[i] == 1) cout << 1 << " ";
        else if (f[i] == 2) cout << 2 << " ";
        else cout << 3 << " ";
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}