#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sherlock() {
	ll n;
	cin >> n;
	int i = 0;
	while (1) {
		ll x = 0;
		ll p = 1;
		for (int j = 1; j <= i; j <<= 1) {
			if (i & j) {
				x = x + p;
			}
			p *= 3;
		}
		if (x >= n) {
			cout << x << endl;
			return;
		}
		i++;
	}
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