#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int> (n));
	int x = 1;
	for (int j = 0; j < n; j++) {
		if (j % 2 == 0) {
			for (int i = 0; i < n; i++) {
				v[i][j] = x;
				x++;
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				v[i][j] = x;
				x++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}