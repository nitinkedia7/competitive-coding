#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple <long long, int, int> ituple;

ll dijksktra(vector<vector<ituple>> &adj, int n, int s, int t, int k) {
    // Dijkstra's SSSP
    priority_queue<ituple, vector<ituple>, greater<ituple> > pq;

    vector<ll> dist(n, LLONG_MAX);
    pq.push(make_tuple(0, k, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = get<2>(pq.top());
        pq.pop();

        for (auto x : adj[u]) {
            int v = get<2>(x);
            long long cost = get<0>(x);
            int value = get<1>(x);

            if ((dist[v] > (dist[u] + cost)) && (k == (k & value))) {
                // cout << k << ", " << value << endl;
                dist[v] = dist[u] + cost;
                pq.push(make_tuple(dist[v], k, v));
            }
        }
    }
    return dist[t];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ituple>> adj(n);
    int a, b, c, v;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> v;
        adj[a-1].push_back(make_tuple(c, v, b-1));
        adj[b-1].push_back(make_tuple(c, v, a-1));
    }
    int s, t, k;
    cin >> s >> t >> k;
    s -= 1;
    t -= 1;

    int cu = 0;
    ll mc = LLONG_MAX;
    for (int i = 29; i >= 0; i--) {
        if (cu + pow(2, i) > k) {
            ll cand = dijksktra(adj, n, s, t, cu + pow(2, i));
            mc = min(mc, cand);
            
        }
        else cu += pow(2, i);
    }
    mc = min(mc, dijksktra(adj, n, s, t, k));
    if (mc == LLONG_MAX) cout << -1 << endl;
    else cout << mc << endl;
}