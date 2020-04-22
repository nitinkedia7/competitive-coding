#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &par, vector<int> &d, vector<pair<int,int>> &lr, int &leaf) {
    par[u] = p;
    if (adj[u].size() == 1 && adj[u][0] == p) {
        lr[u] = {leaf, leaf+1};
        leaf++;
        return;
    }
    lr[u].first = leaf;
    for (auto v : adj[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u, adj, par, d, lr, leaf); 
    }
    lr[u].second = leaf;
    return;
}

void watson(vector<int> &d, vector<int> &p, vector<pair<int,int>> &lr) {
    int n = d.size(), k, u;
    cin >> k;
    vector<pair<int,int>> v;
    for (int i = 0; i < k; i++) {
        cin >> u;
        u--;
        v.push_back({d[u], u});
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    vector<int> par;
    par.push_back(p[v[0].second]);
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first == v[i-1].first && p[v[i].second] != p[v[i-1].second]) {
            cout << "NO" << endl;
            return;
        }
        if (v[i].first != v[i-1].first) {
            par.push_back(p[v[i].second]);
        }
    }
    // for (int i = 0; i < par.size(); i++) cout << par[i] << " ";
    // cout << endl;
    if (par[par.size() - 1] == -1) par.pop_back();
    // for (auto x : par) {
    //     cout << lr[x].first << " " << lr[x].second << endl;
    // }
    for (int i = 1; i < par.size(); i++) {
        int x = par[i], y = par[i-1];
        if (!(lr[x].first <= lr[y].first && lr[x].second >= lr[y].second)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    // int x = par[0];
    // int i = 0;
    // while (x != -1 && i < par.size()) {
    //     if (x == par[i]) i++;
    //     x = p[x];
    // }
    // if (i < par.size() && par[i] == x) i++;
    // if (i == par.size()) cout << "YES" << endl;
    // else cout << "NO" << endl; 
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n), d(n);
    vector<pair<int,int>> lr(n);
    d[0] = 0;
    int leaf = 0;
    dfs(0, -1, adj, p, d, lr, leaf);
    for (int i = 0; i < m; i++) {
        watson(d, p, lr);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}