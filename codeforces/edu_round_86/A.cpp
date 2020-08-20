#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;


void sherlock(int t) {
    ll x, y;
    cin >> x >> y;
    ll a, b;
    cin >> a >> b;
    if (x > y) swap(x, y);
    if (x == 0 && y == 0) {
        cout << 0 << endl;
    }
    else {
        ll c1 = (y-x) * a + x * b;
        ll c2 = (x+y) * a;
        cout << min(c1, c2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}