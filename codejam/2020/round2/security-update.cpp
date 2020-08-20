#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int WEIGHT_MAX = 1e6;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void bfs(int k, int c, vector<int> &roots, vector<vector<int>> &adj, map<int, vector<int>> &mp, map<pair<int,int>, int> &edge_index, map<int,int> &weight, int &max_dist, vector<int> &dist) {
    vector<int> vis(c), par(c, -1);
    queue<int> q;
    for (auto u : roots) {
        q.push(u);
        vis[u] = 1;
    } 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                q.push(v);
                vis[v] = 1;
                par[v] = u;
            }
        }
    }

    vector<vector<int>> v;
    vector<int> cur_par, cur_node;
    for (auto x : mp[k]) {
        roots.push_back(x);
        // cout << x + 1 << " "; 
        vector<int> e;
        int cur = x, p = par[x];
        while (p != -1) {
            e.push_back(edge_index[{p, cur}]);
            cur = p;
            p = par[cur];
        }
        cur_par.push_back(cur);
        cur_node.push_back(x);
        v.push_back(e);
    }
    int lcm = 1;
    for (int i = 0; i < (int) v.size(); i++) {
        int x = v[i].size();
        lcm = (lcm * x) / gcd(x, lcm);
    }
    int m = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        int z = max(0, max_dist - lcm - dist[cur_par[i]] + 1);
        int j = 0;
        for (auto e : v[i]) {
            weight[e] = lcm / (int) v[i].size();
            if (j == 0) weight[e] += z;
            j++;
        }
        dist[mp[k][i]] = dist[cur_par[i]] + lcm + z;
        m = max(m, dist[mp[k][i]]);
    }
    max_dist = max(m, max_dist);
    // cout << lcm_base << endl;
    return;
}

void sherlock(int t) {
    int c, d;
    cin >> c >> d;
    map<int, vector<int>> mp;
    for (int i = 1; i < c; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            mp[-1 * x].push_back(i);
        }
        else {
            exit(0);
        }
    }
    vector<vector<int>> adj(c);
    map<pair<int,int>, int> edge_index;
    int u, v;
    for (int i = 0; i < d; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_index[{u, v}] = i;
        edge_index[{v, u}] = i;
    }
    // Repeated bfs
    vector<int> roots{0};
    map<int,int> weight;
    vector<int> dist(c);
    int lcm = 0;
    for (auto it : mp) {
        bfs(it.first, c, roots, adj, mp, edge_index, weight, lcm, dist);
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < d; i++) {
        if (weight.find(i) == weight.end()) {
            cout << WEIGHT_MAX << " ";
        }
        else {
            cout << weight[i] << " "; 
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
