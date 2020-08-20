#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void dfs(int u, int p, vector<vector<int>> &adj, vector<ll> &a, map<ll,int> mp, ll &ans) {
    map<ll,int> mpu;
    for (auto &[g_old, c] : mp) {
        ll g = gcd(g_old, a[u]);
        mpu[g] += c;
    }
    mpu[a[u]]++;
    for (auto &[g_new, c] : mpu) {
        ans += (c * g_new) % MOD;
        ans %= MOD;
    }
    if (adj[u].size() == 1 && adj[u][0] == p) {
        return;
    }   
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj, a, mpu, ans);
        }
    }
    return;
} 

void sherlock(int t) {
    int n;
    cin >> n; 
    vector<ll> a(n), path;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    map<ll,int> mp;
    dfs(0, -1, adj, a, mp, ans);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
