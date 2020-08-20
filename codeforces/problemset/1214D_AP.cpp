#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

vector<pair<int,int>> off4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// vector<pair<int,int>> off4 = {{1, 0}, {0, 1}};


bool valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool reachable(vector<string> &v, vector<vector<int>> &dp) {
    int n = v.size(), m = v[0].size();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#') continue;
            if (valid(i-1, j, n, m) && dp[i-1][j]) {
                dp[i][j] = 1;
            }
            if (valid(i, j-1, n, m) && dp[i][j-1]) {
                dp[i][j] = 1;
            }
        }
    }
    return dp[n-1][m-1];
}

bool dfs (
    int ux,
    int uy,
    int &time,
    // bool 
    vector<vector<int>> &dp,
    vector<vector<int>> &vis,
    vector<vector<int>> &disc,
    vector<vector<int>> &low,
    vector<vector<pair<int,int>>> &par,
    bool &blocked
) {
    int n = vis.size(), m = vis[0].size();
    vis[ux][uy] = 1;
    disc[ux][uy] = low[ux][uy] = ++time;
    int vx, vy;
    bool ans = false, ap = false;
    for (int i = 0; i < 4; i++) {
        vx = ux + off4[i].first;
        vy = uy + off4[i].second;
        if ((!valid(vx, vy, n, m)) || dp[vx][vy] == 0) continue;
        if (!vis[vx][vy]) {
            par[vx][vy] = {ux, uy};
            ans = dfs(vx, vy, time, dp, vis, disc, low, par, blocked) || ans;
            low[ux][uy] = min(low[ux][uy], low[vx][vy]);
            if ((!(ux == 0 && uy == 0)) && low[vx][vy] >= disc[ux][uy]) {
                // AP found
                ap = true;
                // cout << ux << "," << uy << endl;
            }
        }
        else if (par[ux][uy].first != vx || par[ux][uy].second != vy) {
            low[ux][uy] = min(low[ux][uy], disc[vx][vy]);
        }
    }
    if (ap && ans) {
        blocked = true;
    }
    vis[ux][uy] = 2;
    if (ux == n-1 && uy == m-1) {
        return true;
    }
    return ans;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int> (m));
    if (!reachable(v, dp)) {
        cout << 0 << endl;
        return;
    }  
    // find if an AP exists
    vector<vector<int>> vis(n, vector<int> (m));
    vector<vector<int>> disc(n, vector<int> (m));
    vector<vector<int>> low(n, vector<int> (m));
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>> (m));
    int time = 0;
    bool blocked = false;
    par[0][0] = {-1, -1};
    bool reachable = dfs(0, 0, time, dp, vis, disc, low, par, blocked);
    if (!reachable) {
        cout << 0 << endl;
    }
    else if (blocked) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
    // cout << 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
