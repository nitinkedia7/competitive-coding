#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int find(int x, vector<int> &par) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void join(int x, int y, vector<int> &par, vector<int> &rank) {
    int px = find(x, par), py = find(y, par);
    if (rank[px] >= rank[py]) {
        par[py] = px;
        rank[px] += rank[py];
    }
    else {
        par[px] = py;
        rank[py] += rank[px];
    }
    return;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        adj[v].push_back(u);
    } 
    vector<int> par(n), rank(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 1;
    }
    set<int> roots;
    roots.insert(0);
    for (int v = 1; v < n; v++) {
        map<int,int> m;
        for (auto u : adj[v]) {
            m[find(u, par)]++;
        }
        vector<int> bad;
        for (auto r : roots) {
            int p = find(r, par);
            if (rank[p] > m[p]) {
                join(p, v, par, rank);
                bad.push_back(r);
            }
        }
        for (auto b : bad) roots.erase(b);
        roots.insert(v);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << find(i, par) << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < r.size(); i++) cout << r[i]+1 << " ";
    // cout << endl;
    cout << roots.size()-1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}