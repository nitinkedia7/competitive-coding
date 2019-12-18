#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void insert(set<pair<ll, int>, greater<pair<ll, int>>> &s, map<int,ll> &m, int b, ll d) {
    if (m.find(b) != m.end()) {
        d += m[b];
        s.erase({m[b], b});
        m.erase(b);
    }
    s.insert({d, b});
    m[b] = d;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int u, v;
    ll d;
    multiset<tuple<ll, int, int>, greater<tuple<ll, int, int>>> y;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        y.insert({d, u, v});
    }
    vector<set<pair<ll, int>, greater<pair<ll, int>> >> adj(n + 1);
    vector<map<int,ll>> adk(n + 1);
    while (!y.empty()) {
        ll d2 = get<0> (*y.begin());
        int b = get<1> (*y.begin());
        int c = get<2> (*y.begin());
        y.erase(y.begin());
        if (adj[b].empty()) {
            insert(adj[c], adk[c], b, d2);
        }
        else {
            ll d1 = adj[b].begin()->first;
            int a = adj[b].begin()->second;
            adj[b].erase(adj[b].begin());
            adk[b].erase(a);
            ll z = min(d1, d2);
            if (d1 - z > 0) {
                insert(adj[b], adk[b], a, d1 - z);
            }
            if (d2 - z > 0) {
                y.insert({d2 - z, b, c});
            }
            if (a != c && z > 0) y.insert({z, a, c});
        }
    }
    // cout << p << endl;
    map<pair<int,int>, ll> ans;
    for (int i = 1; i <= n; i++) {
        for (auto it : adj[i]) {
            int a = it.second;
            int b = i;
            ll d = it.first;
            ans[{a, b}] = ans[{a, b}] + d;
            // cout << a << " " << b << " " << d << endl; 
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }
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