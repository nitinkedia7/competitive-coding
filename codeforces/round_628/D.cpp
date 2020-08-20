#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll x, y;
    cin >> x >> y;
    ll a = 0, b = 0, c = 0;
    ll p, q;
    int i = 0;
    while (1) {
        cout << "hi" << endl;
        p = 0;
        q = 0;
        if (x == 0 && y == 1) {
            cout << -1 << endl;
            return;
        }
        else if (x == 1 && y == 0) {
            cout << -1 << endl;
            return;
        }
        else if (x == 0 && y == 0) {
            break;
        }
        else if (x == 1 && y == 1) {
            a |= (1LL << i);
            break;
        }

        int bx = x & 1, by = y & 1;
        if (bx == 1 && by == 0) {
            cout << -1 << endl;
            return;
        }
        else if (bx == 0 && by == 1) {
            cout << -1 << endl;
            return;
        }
        else if (bx == 0 && by == 0) {
            int nbx = (x & 2) / 2, nby = (y & 2) / 2;
            if (nbx == 0 && nby == 1) {
                a |= (1LL << i);
                b |= (1LL << i);
                q = 1;
            }
            else if (nbx == 1 && nby == 0) {
                a |= (1LL << i);
                b |= (1LL << i);
                q = -1;
            }
        }
        else {
            int nbx = (x & 2) / 2, nby = (y & 2) / 2;
            if (nbx == 0 && nby == 1) {
                a |= (1LL << i);
                b |= (1LL << i);
                c |= (1LL << i);
                q = 1;
            }
            else if (nbx == 1 && nby == 0) {
                a |= (1LL << i);
                b |= (1LL << i);
                c |= (1LL << i);
                q = -1;
            }
        }
        x /= 2;
        y /= 2;
        x -= p;
        y -= q;
        i++;
        cout << x << " " << y << endl;
    }
    for (int i = 0; i < 64; i++) {
        if ((a & (1LL << i)) && (b & (1LL << i)) && (c & (1LL << i))) {
            b ^= (1LL << i);
            c ^= (1LL << i);
        }
    }
    ll ans = 1;
    if (b > 0) ans++;
    if (c > 0) ans++;
    cout << ans << endl;
    cout << a << " ";
    if (b != 0) cout << b << " ";
    if (c != 0) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}