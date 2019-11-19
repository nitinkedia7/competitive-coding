#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll func(vector<int> &v, int n, vector<int> &perm, vector<int> &con) {
	vector<int> vis(n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll x = 0;
		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;
			x = x | v[j];
		}
		vis[perm[i]] = 1;
		ans += x;
		con[i] = x;
	}
	return ans;
}

void sherlock() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> per(n);
	for (int i = 0; i < n; i++) {
		per[i] = i;
	}
	ll ans = LLONG_MIN;	
	vector<int> order, con(n), consave;
	do {
		ll c = func(v, n, per, con);
		if (c > ans) {
			ans = c;
			order = per;
			consave = con;
		}
	} while (next_permutation(per.begin(), per.end()));
	cout << ans << endl;
	for (int i = 0 ; i < n; i++) {
		cout << order[i] + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << consave[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		sherlock();
	}
	return 0;
}