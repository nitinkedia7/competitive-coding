#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define C 1001

ll dfs(int u, int l, vector<vector<pair<int,int>>> &adj, int k, vector<int> &color) {
    if (u != 0) l++;
    if (l == k) return 0;
    color[u] = 1;
    ll ans = LLONG_MAX - INT_MAX;
    for (auto neigh: adj[u]) {
        int v = neigh.first;
        int w = neigh.second;
        if (v == 0 || color[v] == 0) {
            ans = min(ans, w + dfs(v, l, adj, k, color));
        }
    }
    cout << u << " " << ans << endl;
    color[u] = 0;
    return ans;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> dogs(n); // pos, color
    for (int i = 0; i < n; i++) {
        cin >> dogs[i].first;
    }    
    for (int i = 0; i < n; i++) {
        cin >> dogs[i].second;
    }
    sort(dogs.begin(), dogs.end());
    vector<vector<pair<int,int>>> adj(n + 1); // edge, weight
    vector<pair<int,int>> lastseen(C, {0, 0}); // id, position of last seen of that color
    int p, c, ap, aid;
    for (int i = 0; i < n; i++) {
        p = dogs[i].first;
        c = dogs[i].second;
        aid = lastseen[c].first;
        ap = lastseen[c].second;
        adj[aid].push_back({i + 1, p - ap}); // previous same color dog
        adj[i+1].push_back({0, p}); // back edge
        lastseen[c] = {i + 1, p};
    }
    for (int i = 0; i <= n; i++) {
        cout << i << ": ";
        for (auto x : adj[i]) {
            cout << x.first << "," << x.second << " ";
        }
        cout << endl;
    }
    vector<int> color(n + 1);
    ll ans = dfs(0, 0, adj, k, color);
    cout << "Case #" << t << ": " << ans << endl;
}   

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}