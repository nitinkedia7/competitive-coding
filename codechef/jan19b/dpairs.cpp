#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int mab = 0; // index of max of b
    for (int i = 0; i < m; i++) {
        if (b[i] > b[mab]) mab = i;
    }
    int mia = 0;
    for (int i= 0; i < n; i++) {
        if (a[i] < a[mia]) mia = i;
    }
    for (int i = 0; i < m; i++) {
        cout << mia << " " << i << endl;
    }
    for (int i = 0; i < n; i++) {
        if (i != mia) {
            cout << i << " " << mab << endl;
        }
    }
    return 0;
}