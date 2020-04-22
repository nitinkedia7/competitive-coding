#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void bm(int u, int p, vector<vector<int>> &adj, vector<int> &vis, vector<int> &color, bool &pos) {
    vis[u] = 1;
    if (adj[u].size() == 1 && adj[u][0] == p) return;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (vis[v] == 0) {
            color[v] = !color[u];
            bm(v, u, adj, vis, color, pos);
        }
        else {
            if (color[v] == color[u]) {
                pos = false;
            }
        }
    }
    vis[u] = 2;
    return;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bool oc = true;
    for (int i = 0; i < n; i++) {
        if (v[i] != v[(i+1) % n]) {
            oc = false;
            break;
        }
    }
    if (oc) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        if (v[i] != v[(i+1) % n]) {
            adj[i].push_back((i+1) % n);
            adj[(i+1)%n].push_back(i);
        }
    }
    vector<int> vis(n), color(n);
    color[0] = 0;
    bool pos = true;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) bm(i, -1, adj, vis, color, pos);
    }
    if (pos) {
        cout << 2 << endl;
        for (int i = 0; i < n; i++) {
            cout << color[i] + 1 << " ";
        }
        cout << endl;
        return;
    }
    color[0] = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]) color[i] = color[i-1];
        else color[i] = !color[i-1];
    }
    color[n-1] = 2;
    cout << 3 << endl;
    for (int i = 0; i < n; i++) {
        cout << color[i] + 1 << " ";
    }
    cout << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}