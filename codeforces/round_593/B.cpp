#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll modexp(ll x, ll y) { // x^y
	ll p = 1;
	for (int i = 31; i >= 0; i--) {
		p *= p;
		p %= MOD;
		if (y & (1 << i)) {
			p *= x; 
			p %= MOD;
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	ll base = modexp(2, m);
	base += MOD - 1;
	base %= MOD;
	cout << modexp(base, n) << endl;
	return 0;
}