#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void dfs(int u, vector<vector<int>> &adj, vector<int> &color, int &s) {
    color[u] = 1;
    s++;
    for (auto v : adj[u]) {
        if (color[v] == 0) {
            dfs(v, adj, color, s);
        }
    } 
    color[u] = 2;
}

ll pg(int a, int b, vector<pair<int,int>> &edges, int n, int a1, int b1) {
    vector<vector<int>> adj(n + 1);
    int m = edges.size();
    for (int i = 0; i < m; i++) {
        if (edges[i].first == a || edges[i].first == b) continue;
        if (edges[i].second == a || edges[i].second == b) continue;
        int u = edges[i].first, v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, sa = 0, sb = 0;
    ll ans = 0;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            s = 0;
            dfs(i, adj, color, s);
            ans += (s * 1LL * (s-1)) / 2;
            if (sa == 0 && color[a1] == 2) {
                sa = 1;
                // cout << "hi " << (s - 1) << endl;
                ans -= (s - 1);
            } 
            if (sb == 0 && color[b1] == 2) {
                sb = 1;
                ans -= (s - 1);
            }
        }
    }
    cout << ans << endl;
    adj.clear();
    color.clear();
    return ans;
}

void sherlock(int x) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<pair<int,int>> edges(m);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
    }
    ll ans = 0;
    ans += pg(a, -1, edges, n, a, b);
    ans += pg(-1, b, edges, n, a, b);
    ans -= pg(a, b, edges, n, a, b);
    n -= 2;
    ll t = (n * 1LL * (n-1)) / 2;
    // cout << endl;
    cout << t << endl;
    cout << t - ans << endl;
    // cout << endl;
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