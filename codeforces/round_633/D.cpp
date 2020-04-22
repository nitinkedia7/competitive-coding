#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &parity, vector<int> &type) {
    // cout << u << " " << p << endl;
    parity[u] = !parity[p];
    if (adj[u].size() == 1 && p == adj[u][0]) {
        type[u] = 1; // leaf
        return;
    }
    type[u] = 2; // non-leaf internal
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, adj, parity, type);
        if (type[v] == 1) {
            type[u] = 3; // external non-leaf
        }
    }
    return;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int r = -1;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            r = i;
            break;
        }
    }
    // cout << r << endl;
    vector<int> parity(n), type(n);
    parity[r] = 0;
    type[r] = 1;
    dfs(adj[r][0], r, adj, parity, type);
    // return;
    type[adj[r][0]] = 3;
    int mi = 1;
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (type[i] != 1) continue;
        if (x == -1) x = parity[i];
        else if (x != parity[i]) {
            mi = 3;
        }
    }
    int l = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if (type[i] == 1) l++;
        if (type[i] == 3) m++; 
    }
    // for (int i = 0; i < n; i++) {
    //     cout << type[i] << " ";
    // }
    // cout << endl;
    cout << mi << " " << n-1-l+m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}