#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = 0; j < (int) v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

bool all_colors(int r, int n, vector<vector<int>> &adj, vector<int> &col, vector<int> &vis, vector<int> &forest, int f, int &x, int &y) {
    queue<int> q;
    q.push(r);
    vis[r] = 1;
    col[r] = 0;
    while (!q.empty()) {
        int u = q.front();
        forest[u] = f;
        if (col[u] == 0) x++;
        else y++;
        q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
                col[v] = !col[u];
            }
            else if (col[v] == col[u]) {
                return false;
            } 
        }
    }
    return true;
}

bool exactly_one(int n1, int n2, int n3, int &x) {
    if (!n1 && !n2 && n3) {
        x = 3;
        return true;
    }
    if (!n1 && n2 && !n3) {
        x = 2;
        return true;
    }
    if (n1 && !n2 && !n3) {
        x = 1;
        return true;
    }
    return false;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x;
    if (exactly_one(n1, n2, n3, x)) {
        if (m == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << x;
            }
            cout << endl;
            return;
        }
    }
    else if (n2 == 0) {
        if (m == 0) {
            for (int i = 0; i < n1; i++) {
                cout << 1;
            }
            for (int i = 0; i < n3; i++) {
                cout << 3;
            } 
            cout << endl;
            return;
        }
    }
    else {
        vector<int> col(n), vis(n), forest(n);
        vector<pair<int,int>> v;
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int x = 0, y = 0;
                if (!all_colors(i, n, adj, col, vis, forest, f, x, y)) {
                    cout << "NO" << endl;
                    return;
                }
                f++;
                v.push_back({x, y});
                // cout << i << " " << x << " " << y << endl;
            }
        }
        // print(col);
        // print(forest);
        // 2D dp
        int k = v.size();
        vector<vector<int>> dp(k + 1, vector<int> (n2 + 1, 0));
        vector<vector<int>> par(k + 1, vector<int> (n2 + 1, -1));
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= n2; j++) {
                int x = v[i-1].first, y = v[i-1].second;
                if (j >= x && dp[i-1][j-x]) {
                    dp[i][j] = 1;
                    par[i][j] = 0;
                }
                else if (j >= y && dp[i-1][j-y]) {
                    dp[i][j] = 1;
                    par[i][j] = 1;
                }
            }
        }
        // print2d(dp);
        if (dp[k][n2] == 1) {
            cout << "YES" << endl;
            vector<int> z;
            int i = k, j = n2;
            while (i > 0) {
                z.push_back(par[i][j]);
                if (par[i][j] == 0) j -= v[i-1].first;
                else j -= v[i-1].second;
                i--;
            } 
            reverse(all(z));
            for (int i = 0; i < n; i++) {
                if (col[i] == z[forest[i]]) {
                    cout << 2;
                }
                else if (n1 > 0) {
                    cout << 1;
                    n1--;
                }
                else if (n3 > 0) {
                    cout << 3;
                    n3--;
                }   
            }
            cout << endl;
            return;
        } 
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
