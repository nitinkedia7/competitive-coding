#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int tc) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
    }
    set<int> nt;
    for (int u = 0; u < n; u++) {
        // blog u
        nt.clear();
        for (auto v : adj[u]) {
            nt.insert(t[v]);
        }
        // nei must have all topics in [0, t[u]) and not have n
        if (nt.find(t[u]) != nt.end()) {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < t[u]; i++) {
            if (nt.find(i) == nt.end()) {
                cout << -1 << endl;
                return;
            }
        }
    } 
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({t[i], i});
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        cout << v[i].second + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
