#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int u, v;
    ll d;
    map<pair<int,int>, ll> book;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        book[{u, v}] = book[{u, v}] + d;
        // y.insert({d, u, v});
    }
    multiset<tuple<ll, int, int>, greater<tuple<ll, int, int>>> y;
    for (auto it : book) {
        y.insert({it.second, it.first.first, it.first.second});
    }
    int p = 0;
    vector<set<pair<ll, int>, greater<pair<ll, int>> >> adj(n + 1);
    while (!y.empty()) {
        ll d2 = get<0> (*y.begin());
        int b = get<1> (*y.begin());
        int c = get<2> (*y.begin());
        y.erase(y.begin());
        if (adj[b].empty()) {
            adj[c].insert({d2, b});
            p++;
        }
        else {
            ll d1 = adj[b].begin()->first;
            int a = adj[b].begin()->second;
            adj[b].erase(adj[b].begin());
            p--;
            ll z = min(d1, d2);
            if (d1 - z > 0) {
                adj[b].insert({d1 - z, a});
                p++;
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