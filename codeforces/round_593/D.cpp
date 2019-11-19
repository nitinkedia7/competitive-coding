#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m , k;
	cin >> n >> m >> k;
	vector<pair<int,int>> obs(k), obs2;
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		obs[i] = {x - 1, y - 1};
	}
	for (int i = 0; i < n; i++) {
		obs.push_back({i, m});
		obs.push_back({i, -1});
	}
	for (int j = 0; j < m; j++) {
		obs.push_back({-1, j});
		obs.push_back({n, j});
	} 
	sort(obs.begin(), obs.end());
	for (int i = 0; i < obs.size(); i++) {
		obs2.push_back({obs[i].second, obs[i].first});
	}
	sort(obs2.begin(), obs2.end());
	x = 1, y = 1;
	int d = 1;
	pair<int,int> p, q;
	int i;
	while (1) {
		switch (d) {
			case 1:
				q = {x, y};
				i = lower_bound(obs.begin(), obs.end(), q) - obs.begin();
				p = obs[i];
				if (p.second < m) {
					cout << "NO" << endl;
					return 0;
				}
				else {
					x = p.first;
					y = p.second - 1;
					d = 2;
				}
				break;
			case 2:
				q = {y, x};
				i = lower_bound(obs2.begin(), obs2.end(), q) - obs.begin();
				p = obs[i];
				if (p.first < n) {
					cout << "NO" << endl;
					return 0;
				}
				else {
					x = p.first;
					y = p.second - 1;
					d = 2;
				}
				break;
		}
	}

	return 0;
}