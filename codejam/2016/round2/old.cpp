#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool find_path(int source, int sink, vector<set<int>> &adj) {
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

bool is_feasible(int n, int skill) {
    int source = 2 * n, sink = 2 * n + 1;
    for (int w = 0; w < n; w++) {
        int sw = 0;
        for (int j = 0; j < n; j++) {
            if (skill & (1 << (w * n + j))) {
                sw++;
            }
        }
        // build graph
        vector<set<int>> adj(2 * n + 2);
        for (int i = 0; i < n; i++) {
            if (i == w) continue;
            for (int j = 0; j < n; j++) {
                // if w doesn't know j'th machine continue
                if (!(skill & (1 << (w * n + j)))) continue;
                if (skill & (1 << (i * n + j))) {
                    adj[i].insert(n + j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            adj[source].insert(i);
            adj[n + i].insert(sink);
        }
        int f = 0;
        while (find_path(source, sink, adj)) {
            f++;
        }
        if (f == sw) return false;
    }
    return true;
}

void sherlock(int t) {
    int n;
    cin >> n;
    int og_skill = 0;
    char x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == '1') og_skill |= (1 << (i * n + j));
        }
    }
    if (n > 4) {
        exit(0);
    }    
    int p = pow(2, (n * n));
    int min_cost = n * n;
    for (int i = 0; i < p; i++) {
        int skill = (i | og_skill);
        // cout << skill << endl;
        if (is_feasible(n, skill)) {
            // cout << "hi" << endl;
            min_cost = min(
                min_cost,
                __builtin_popcount(skill) - __builtin_popcount(og_skill)
            );
        }
    }
    cout << "Case #" << t << ": " << min_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
