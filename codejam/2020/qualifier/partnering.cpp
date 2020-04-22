#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void dfs(int u, int n, vector<vector<int>> &adj, vector<int> &color, vector<int> &side, bool &feasible) {
    color[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 0) continue;
        if (color[v] == 0) {
            side[v] = !side[u];
            dfs(v, n, adj, color, side, feasible);
        }
        else if (side[u] == side[v]) {
            feasible = false;
        }
    }
    color[u] = 2;
    return;
}

bool no_overlap(pair<int,int> &x, pair<int,int> &y) {
    if (x.second <= y.first) return true;
    if (y.second <= x.first) return true;
    return false;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int s, e;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        v[i] = {s, e};
    }
    vector<vector<int>> adj(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!no_overlap(v[i], v[j])) {
                adj[i][j] = 1;
            }
        }
    }
    // bipartite colouring
    vector<int> color(n, 0), side(n, -1);
    bool feasible = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            side[i] = 0;
            dfs(i, n, adj, color, side, feasible);
        }
    }
    cout << "Case #" << t << ": ";
    if (!feasible) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            assert(side[i] != -1);
            if (side[i] == 0) {
                cout << "C";
            }
            else {
                cout << "J";
            }
        }
        cout << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}