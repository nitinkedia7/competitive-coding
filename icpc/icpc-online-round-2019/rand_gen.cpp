#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    srand(time(0));
    int n;
    cin >> n;
    cout << 1 << endl;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand() << " ";
    }
    cout << endl;
	return 0;
}