#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define C 1001

ll djikstra(int u, ll d, vector<vector<pair<int,int>>> &adj, int n, int k) {
    multiset<pair<ll, int>> pq;
    vector<int> vis(n);
    // cout << u << "," << d << " "; 
    pq.insert({d, u});
    int seen = 0;
    int v, w;
    while (seen < k) {
        u = pq.begin()->second;
        if (vis[u]) {
            pq.erase(pq.begin());
            continue;
        }
        d = pq.begin()->first;
        pq.erase(pq.begin());
        for (auto neigh : adj[u]) {
            v = neigh.first;
            w = neigh.second;
            pq.insert({d + w, v});
        }
        cout << u << "," << d << " "; 
        vis[u] = 1;
        seen++;
    }
    cout << endl;
    return d;
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
    // Graph construction DONE
    vector<vector<pair<int,int>>> adj(n); // edge, weight
    ll w;
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n; j++) {
            if (i == j) continue;
            if (dogs[i].second == dogs[j].second) {
                // color is same; i -> j
                if (dogs[i].first < dogs[j].first) {
                    adj[i].push_back({j, dogs[j].first - dogs[i].first});
                }
            }
            else {
                w = dogs[i].first + dogs[j].first;
                adj[i].push_back({j, w});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto x : adj[i]) {
            cout << x.first << "," << x.second << " ";
        }
        cout << endl;
    }
    vector<pair<int,int>> firstdog(C, {-1, INT_MAX});
    for (int i = 0; i < n; i++) {
        int c = dogs[i].second;
        if (firstdog[c].second > dogs[i].first) {
            firstdog[c] = {i, dogs[i].first};
        }  
    }
    ll ans = LLONG_MAX;
    for (int c = 0; c < C; c++) {
        if (firstdog[c].first != -1) {
            ans = min(ans, djikstra(firstdog[c].first, firstdog[c].second, adj, n, k));
        }
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}