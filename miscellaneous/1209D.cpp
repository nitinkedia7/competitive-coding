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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, u, v;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int h = 0;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            int s = 0;
            dfs(i, adj, color, s);
            h += (s - 1);
        }
    }
    cout << k - h << endl;
    return 0;
}