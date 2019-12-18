#include <bits/stdc++.h>
using namespace std;

void print2d(vector<vector<int>> &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

vector<pair<int,int>> impos = {{1,2},{1,3},{1,4},{1,5},{2,2},{2,3},{2,4},{3,3}};

void dfs(int u, vector<vector<int>> &adj, vector<int> &color, int l, bool &possible, vector<pair<int,int>> &path, int c) {
	if (possible) return;	
	int n = adj.size();
	color[u] = 1;
	path.push_back({u / c, u % c});
	l++;

	vector<int> perm(adj[u].size());
	for (int i = 0; i < adj[u].size(); i++) perm[i] = i;
	random_shuffle(perm.begin(), perm.end());
	possible = possible || (l == n);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][perm[i]];
		if (possible) break;
		if (color[v] == 0) {
			dfs(v, adj, color, l, possible, path, c);			
		}	
	}
	perm.clear();
	color[u] = 0;
	if (!possible) path.pop_back();
	return;
}

void sherlock(int t) {
	int r, c;
	cin >> r >> c;
	// if (r > c) swap(r, c);
	pair<int,int> dim = {r, c}, dim2 = {c, r};	
	for (int i = 0; i < impos.size(); i++) {
		if (dim == impos[i] || dim2 == impos[i]) {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
			return;		
		}	
	}
	// random traversal in graph
	int n = r * c;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = i / c, y = i % c;
			int nx = j / c, ny = j % c;
			if (!(x == nx || y == ny || x + y == nx + ny || x - y == nx - ny)) {
				adj[i].push_back(j);				
			}		
		}	
	}
	//print2d(adj);
	bool possible = false;
	vector<int> color(n);
	vector<int> perm(n);
	vector<pair<int,int>> path;
	for (int i = 0; i < n; i++) perm[i] = i;
	random_shuffle(perm.begin(), perm.end());
	for (int i = 0; i < n; i++) {
		dfs(perm[i], adj, color, 0, possible, path, c);  		
	}
	if (possible) {
		cout << "Case #" << t << ": POSSIBLE" << endl;
		for (auto p : path) cout << p.first + 1 << " " << p.second + 1 << endl;	
	}
	else cout << "Case #" << t << ": IMPOSSIBLE" << endl;
	return;
}

int main() {
	srand(unsigned(time(0)));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) sherlock(i);	
}
