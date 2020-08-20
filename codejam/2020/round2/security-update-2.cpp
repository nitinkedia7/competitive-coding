#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int WEIGHT_MAX = 1e6;

void bfs(
    int k,
    int c,
    vector<int> &roots,
    vector<vector<int>> &adj,
    map<int, vector<int>> &mp,
    map<pair<int,int>, int> &edge_index,
    map<int,int> &weight,
    int &max_dist,
    vector<int> &dist
) {
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
    int new_max_dist = 0;
    for (auto x : mp[k]) {
        roots.push_back(x);
        int p = par[x];
        int e = edge_index[{p, x}];
        if (dist[x] != -1) {
            weight[e] = dist[x] - dist[p];
        }
        else {
            weight[e] = max_dist - dist[p] + 1;
            dist[x] = max_dist + 1;
        }
        // cout << p << "->" << x << " " << weight[e] << endl;
        new_max_dist = max(new_max_dist, dist[x]);
    }
    max_dist = new_max_dist;
}

void sherlock(int t) {
    int c, d;
    cin >> c >> d;
    map<int, vector<int>> mp_count, mp_dist, mp_layer;
    vector<int> dist(c, -1);
    dist[0] = 0;
    for (int i = 1; i < c; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            mp_count[-1 * x].push_back(i);
        }
        else {
            dist[i] = x;
            mp_dist[x].push_back(i);
        }
    }
    auto l = mp_count.begin(), r = mp_dist.begin();
    int cx = 1;
    while (l != mp_count.end()) {
        while (cx < l->first) {
            mp_layer[cx] = r->second;
            cx += r->second.size();
            r++;
        }
        mp_layer[cx] = l->second;
        cx += l->second.size();
        l++;
    }
    while (r != mp_dist.end()) {
        mp_layer[cx] = r->second;
        cx += r->second.size();
        r++;
    }
    // for (auto it : mp_layer) {
    //     cout << it.first << ": ";
    //     for (auto x : it.second) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

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
    int lcm = 0;
    for (auto it : mp_layer) {
        bfs(it.first, c, roots, adj, mp_layer, edge_index, weight, lcm, dist);
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
