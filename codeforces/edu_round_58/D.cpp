#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
#define pi pair<int, int>
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

void dfs(int u, int p, vector<vector<int>> &adj, vector<vector<pi>> &dp, vector<int> &a, int &ans) {
    vector<pi> chd;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, adj, dp, a, ans);
        for (auto y : dp[v]) {
            chd.pb(y);
        }
    }
    sort(all(chd));
    int i = 0, j = 0;
    while (i < chd.size()) {
        j = i-1;
        while (j+1 < chd.size() && chd[i].f == chd[j+1].f) {
            j++;
        }
        if (a[u] % chd[i].f == 0) {
            if (i == j) ans = max(ans, chd[j].s + 1);
            else ans = max(ans, chd[j].s + chd[j-1].s + 1);
            
            dp[u].pb(mp(chd[i].f, chd[j].s + 1)); 
            
            while (a[u] % chd[j].f == 0) a[u] /= chd[j].f;
        }
        // else ans = max(ans, chd[j].s);
        i = j+1;
    }
    for (int k = 2; k * k <= a[u]; k++) {
        if (a[u] % k == 0) {
            ans = max(ans , 1);
            dp[u].pb(mp(k, 1));
            while (a[u] % k == 0) a[u] /= k;
        }
    }
    if (a[u] > 1) {
        ans = max(ans , 1);        
        dp[u].pb(mp(a[u], 1));
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<vector<pi>> dp(n);
    int ans = 0;
    dfs(0, -1, adj, dp, a, ans);
    cout << ans << endl;
    return 0;
}