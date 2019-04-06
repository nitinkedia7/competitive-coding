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
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n, p;
        cin >> n >> p;
        ll a = 1, b = 1, c = 1, m;
        if (n % 2 == 0) m = n/2 -1;
        else m = n/2;
        ll ans = 1;
        if (m == 0) {
            ans = ans * p;
            ans = ans * p;
            ans = ans * p;
            cout << ans << endl;
        }
        else {
            a = (p - m) * 1LL * (p - m);
            b = (p - n) * 1LL * (p - m);
            c = (p - n) * 1LL * (p - n);
            ans = a + b + c;
            cout << ans << endl;
        }
    }
    return 0;
}