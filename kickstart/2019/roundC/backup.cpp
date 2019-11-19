#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define C 1001

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
    // TODO: home edges DONE
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
    // Djikstra
    multiset<pair<ll,int>> pq;
    vector<int> vis(n + 1); 
    pq.insert({0, 0});
    int seen = 0;
    ll d, w;
    int u, v, lastcolor = 0;
    while (seen < k) {
        u = pq.begin()->second;
        d = pq.begin()->first;
        if (u == 0) c = 0;
        else c = dogs[u-1].second;
        pq.erase(pq.begin());
        if (vis[u] == 1 || lastcolor !) {
            continue;        
        }  
        for (auto neigh : adj[u]) {
            v = neigh.first;
            w = neigh.second;
            pq.insert({d + w, v});
        }
        if (u != 0) {
            seen++;
            cout << u << "," << d << endl;
            vis[u] = 1;
        }
    }
    cout << "Case #" << t << ": " << d << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}