#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll myexp(vector<int> &v) {
	ll x = 0;
	ll p = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) x += p;
		p *= 3;
	}
	return x;
}
   
void sherlock() {
	ll n;
	cin >> n;
	vector<int> v;
	ll x = n;
	while (x > 0) {
		v.push_back(x % 3);
		x /= 3;
	}
	v.push_back(0);
	int l = v.size(), p2 = -1, p0 = -1;
	for (int i = 0; i < l; i++) {
		if (v[i] == 2) {
			p2 = i;
		}
	}
	if (p2 == -1) {
		cout << n << endl;
	}
	else {
		for (int i = 0; i < l; i++) {
			if (i > p2 && v[i] == 0) {
				v[i] = 1;
				break;
			}
			v[i] = 0;
		}
		cout << myexp(v) << endl;
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