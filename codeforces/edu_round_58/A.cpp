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
    int q;
    int l, r, d;
    cin >> q;
    for (; q > 0; q--) {
        cin >> l >> r >> d;
        if (d < l) cout << d << endl;
        else {
            if (r % d == 0) cout << r + d << endl;
            else cout << d * (r/d + 1) << endl;
        }
    }
    return 0;
}