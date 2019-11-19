#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sherlock() {
	int a, b, c;
	cin >> a >> b >> c;
	int coins = min(c / 2, b);
	b -= coins;
	coins += min(a, b / 2);
	cout << 3 * coins << endl;
}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) sherlock();
	return 0;
}