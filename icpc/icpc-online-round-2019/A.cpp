#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock() {
	int n;
	cin >> n;
	vector<int> v;
	int x = n;
	for (int i = 0; i < 10; i++) {
		v.push_back(x % 10);
		x /= 10;
	}
	// 123 -> 3 2 1
	// int l = v.size();
	// vector<int> lsb(l), msb(l);
	// lsb[0] = v[0];
	// int p = 10;
	// for (int i = 1; i < l; i++) {
	// 	lsb[i] = lsb[i-1] + p * v[i]; 
	// 	p *= 10;
	// }
	// for (int i = l - 1; i >= 0; i--) {
	// 	msb 
	// }
	int l = v.size(), ma = INT_MAX;
	for (int i = 0; i < l; i++) {
		int p = 1;
		x = 0;
		for (int j = 0; j < l; j++) {
			if (i == j) continue;
			x += p * v[j];
			p *= 10;
		}
		if (x < ma) ma = x;
	} 
	cout << ma << endl;
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