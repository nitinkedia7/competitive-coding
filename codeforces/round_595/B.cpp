#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int u, vector<int> &adj, vector<int> &color, vector<int> &tid, int t) {
	color[u]= 1;
	tid[u] = t;
	int v = adj[u];
	if (color[v] == 0) dfs(v, adj, color, tid, t);
	color[u] = 2;
}

void sherlock() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	vector<int> color(n + 1), tid(n + 1);
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			dfs(i, v, color, tid, t);
			t++;
		}
	}
	vector<int> size(t);
	for (int i = 1; i <= n; i++) {
		size[tid[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << size[tid[i]] << " ";
	}
	cout << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int q;
	cin >> q;
	while (q--) {
		sherlock();
	}
	return 0;
}