#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sherlock() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		if (v[i] - v[i-1] == 1) {
			cout << 2 << endl;
			return;
		} 
	} 
	cout << 1 << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		sherlock();
	}
	return 0;
}