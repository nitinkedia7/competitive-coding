#include <bits/stdc++.h>
using namespace std;

int factorise(int p) {
	for (int i = 2; i*i <= p; i++) {
		if (p % i == 0) return i;
	}
	return 0;
	// assert(false);
}

int dis(vector<int> &v, int x) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == x) return i;
	}
	return -1;
}

int main ()
{
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		int n, l;
		cin >> l >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		int x = factorise(v[0]);
		for (int i = 0; i < n; i++) {
			if (v[i] != v[0]) {
				if (i % 2 == 1) {
					if (v[i] % x != 0) x = v[0]/x;
				}
				else {
					if (v[i] % x == 0) x = v[0]/x;
				}
				break;
			}
		}
		// if (v[1] % x != 0) x = v[0]/x; // x divides both 0 and 1

		vector<int> v2(n+1);
		v2[0] = v[0]/x;
		for (int i = 1; i < n; i++) {
			v2[i] = x;
			x = v[i]/x;
		} 
		v2[n] = x;
		vector<int> v3 = v2;
		sort(v3.begin(), v3.end());
		vector<int> v4;
		v4.push_back(v3[0]);
		for (int i = 1; i < v3.size(); i++) {
			if (v3[i] != v3[i-1]) {
				v4.push_back(v3[i]);
			}
		}
		cout << "Case #" << c << ": ";
		for (int i = 0; i <= n; i++) {
			int p = dis(v4, v2[i]);
			cout << char('A'+p);
		}
		// v.clear();
		// v2.clear();
		// s.clear();
		cout << endl;
	}
	return 0;
}