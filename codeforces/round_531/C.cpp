#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (x > y) {
        cout << n << endl;
        return 0;
    }
    else {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] <= x) k++;
        }
        if (k % 2 == 0) {
            cout << k/2 << endl;
        }
        else cout << k/2 + 1 << endl;
    }
    return 0;   
}