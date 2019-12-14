#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void bfs(vector<int> &v, vector<vector<int>> &adj, int p, int n, vector<int> &dist) {
    queue<pair<int,int>> q;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (v[i] % 2 == p) {
            vis[i] = 1;
            q.push({i, 0});
        }   
    }
    int u, l;
    while (!q.empty()) {
        u = q.front().first;
        l = q.front().second;
        q.pop();
        dist[u] = l;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push({v, l + 1});
            }
        }
    }
    return;
}

void sherlock(int t) {
    int n, a;
    cin >> n;
    vector<int> v(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v[i] = a;
        if (i - a >= 1) adj[i - a].push_back(i);
        if (i + a <= n) adj[i + a].push_back(i);
    }
    vector<int> distfrom0(n + 1, -1), distfrom1(n + 1, -1);
    bfs(v, adj, 0, n, distfrom0);
    bfs(v, adj, 1, n, distfrom1);
    // print(distfrom0);
    // cout << endl;
    // print(distfrom1);
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        if (v[i] % 2 == 0) {
            cout << distfrom1[i] << " ";
        }
        else cout << distfrom0[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}