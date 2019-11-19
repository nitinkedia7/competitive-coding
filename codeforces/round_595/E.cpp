#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, c, w;
	cin >> n >> c;
	vector<vector<pair<int,int>>> adj(2 * n);
	for (int i = 0; i < n - 1; i++) {
		cin >> w;
		w *= 2;
		adj[i].push_back({i + 1, w});
		adj[i+1].push_back({i, w});
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> w;
		w *= 2;
		adj[n + i].push_back({n + i + 1, w});
		adj[n+i+1].push_back({n + i, w});
	}	
	for (int i = 0; i < n; i++) {
		adj[i].push_back({n+i, c});
		adj[n+i].push_back({i, c});
	}
	multiset<pair<ll, int>> pq;
	vector<int> vis(2 * n);
	vector<ll> dist(2 * n, INT_MAX);
	ll d;
	int u;
	dist[0] = 0;
	pq.insert({0, 0});
	while (!pq.empty()) {
		d = pq.begin()->first;
		u = pq.begin()->second;
		pq.erase(pq.begin());
		if (vis[u]) continue;
		dist[u] = d;
		for (auto p : adj[u]) {
			int v = p.first;
			int w = p.second;
			if (dist[v] > d + w) {
				dist[v] = d + w;
				pq.insert({dist[v], v});
			}
		}
		vis[u] = 1;
	}
	for (int i = 0; i < n; i++) {
		cout << dist[i] / 2 << " ";
	}
	cout << endl;
	return 0;
}