#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(vector<ll> &v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void print1(vector<int> &v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, w;
    vector<vector<pair<int,int>>> adj(n);
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        x--, y--;
        edges.push_back({x, y});
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    multiset<tuple<ll,int,int,int>> pq;
    pq.insert(make_tuple(0LL, 0, 0, -1)); // dist, edge count, vertex, par
    vector<int> vis(n), mec(n), par(n);
    vector<ll> dist(n);
    tuple<ll,int,int,int> t;
    ll d;
    int e, u, p;
    while (!pq.empty()) {
        t = *pq.begin();
        d = get<0> (t);
        e = get<1> (t);
        u = get<2> (t);
        p = get<3> (t);
        pq.erase(pq.begin());
        if (vis[u]) {
            if (dist[u] == d && e < mec[u]) {
                mec[u] = e;
                par[u] = p;
            }
            continue;
        }
        vis[u] = 1;
        dist[u] = d;
        mec[u] = e;
        par[u] = p;
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            pq.insert(make_tuple(d + w, e + 1, v, u));
        }
    }
    // print(dist);
    // print1(par);
    // print1(mec);
    // cout << endl;
    vector<tuple<int,int,int>> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = make_tuple(mec[i], i, par[i]);
    }
    vis.clear();
    // par.clear();
    mec.clear();
    // return 0;
    sort(nodes.begin(), nodes.end(), greater<tuple<int,int,int>>());
    vector<int> weight(n, 1);
    for (int i = 0; i < n; i++) {
        u = get<1> (nodes[i]);
        p = get<2> (nodes[i]);
        if (p != -1) weight[p] += weight[u];
    }
    // print1(weight);
    vector<pair<int,int>> final;
    for (int i = 0; i < m; i++) {
        x = edges[i].first;
        y = edges[i].second;
        if (par[x] == y || par[y] == x)
            final.push_back({min(weight[x], weight[y]), i+1});
        else final.push_back({0, i + 1});
    }
    sort(final.begin(), final.end());
    cout << k << endl;
    for (int i = m - k; i < m; i++) {
        cout << final[i].second << " ";
    }    
    cout << endl;
    return 0;
}