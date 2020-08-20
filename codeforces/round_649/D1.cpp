#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(set<int> &s) {
    cout << 1 << endl;
    for (auto u : s) {
        cout << u + 1 << " ";
    }
    cout << endl;
}

bool linked_to_set(int u, vector<vector<int>> &adj, set<int> &s) {
    for (auto v : adj[u]) {
        if (s.find(v) != s.end()) {
            return true;
        }
    }
    return false;
}

void dfs(int u, int k, vector<vector<int>> &adj, vector<int> &vis, vector<int> &par, vector<int> &path) {
    vis[u] = 1;
    if (adj[u].size() == 1) {
        vis[u] = 2;
        return;
    }
    path.push_back(u);
    for (auto v : adj[u]) {
        if (v == par[u] || v >= k) continue;
        if (vis[v] == 0) {
            par[v] = u;
            dfs(v, k, adj, vis, par, path);    
        }
        else {
            cout << 2 << endl << path.size() << endl;
            for (auto x : path) {
                cout << x + 1 << " ";
            }
            cout << endl;
            exit(0);
        }
    }
    vis[u] = 2;
    path.pop_back();
}

void sherlock(int t) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> left, right;
    for (int u = 0; u < k; u++) {
        // cout << u + 1 << endl;
        // print(left);
        // print(right);
        // cout << endl;
        bool left_link = linked_to_set(u, adj, left);
        bool right_link = linked_to_set(u, adj, right);
        if (!left_link) {
            left.insert(u);
        }
        else if (!right_link) {
            right.insert(u);
        }
        else {
            // find cycle and print it
            vector<int> vis(n, 0), par(n, -1), path;
            for (int r = 0; r < k; r++) {
                if (vis[r] == 0) {
                    dfs(r, k, adj, vis, par, path);
                }
            }
            return;
        }
        // cout << u+1 << ": " << left.size() << " " << right.size() << endl;
    }
    if ((int) left.size() > (int) right.size()) {
        assert((int) left.size() == (k + 1) / 2);
        print(left);
    }
    else {
        assert((int) right.size() == (k + 1) / 2);
        print(right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
