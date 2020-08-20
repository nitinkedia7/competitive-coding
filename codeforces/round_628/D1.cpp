#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll x, y;
    cin >> x >> y;
    ll a = 0, b = 0, c = 0, p = 0;
    for (int i = 0; i < 64; i++) {
        int bx = x & 1, by = y & 1;
        if ((bx ^ p) != by) {
            cout << -1 << " " << i << endl;
            return;
        } 

        if (x == 0 && y == 0) break;
        else if (x == 0 && y == 1) {
            break;
        }
        else if (x == 1 && y == 0) {
            cout << -1 << " " << i << endl;
            return;
        }
        else if (x == 1 && y == 1) {
            a |= (1LL << i);
            break;
        }
        
        int nbx = (x & 2) / 2, nby = (y & 2) / 2;
        if (bx == 0 && by == 0) {
            if (nbx == 0 && nby == 1) {
                a |= (1LL << i);
                b |= (1LL << i);
                p = 1;
            }
            else if (nbx == 1 && nby == 0) {
                a |= (1LL << i);
                b |= (1LL << i);
                p = 1;
            }
        }
        else if (bx == 0 && by == 1) {
            if (nbx == 0 && nby == 0) {
                p = 0;
            }
            else if (nbx == 0 && nby == 1) {
                a |= (1LL << i);
                b |= (1LL << i);
                p = 1;
            }
            else if (nbx == 1 && nby == 0) {
                a |= (1LL << i);
                b |= (1LL << i);
                p = 1;
            }
            else {
                p = 0;
            }
        }
        else if (bx == 1 && by == 0) {
            if (nbx == 0 && nby == 0) {
                p = 1;
            }
            else if (nbx == 0 && nby == 1) {
                a |= (1LL << i);
                p = 1;
            }
            else if (nbx == 1 && nby == 0) {
                a |= (1LL << i);
                p = 1;
            }
            else {
                p = 1;
            }
        }
        else { // 1 1 
            if (nbx == 0 && nby == 0) {
                a |= (1LL << i);
                p = 0;
            }
            else if (nbx == 0 && nby == 1) {
                a |= (1LL << i);
                b |= (1LL << i);
                c |= (1LL << i);
                p = 1;
            }
            else if (nbx == 1 && nby == 0) {
                a |= (1LL << i);
                b |= (1LL << i);
                c |= (1LL << i);
                p = 1;
            }
            else {
                a |= (1LL << i);
                p = 0;
            }
        }
        x /= 2LL;
        y /= 2LL;
        // cout << x << " " << y << endl;
    }
    ll ans = 0;
    if (a > 0) ans++;
    if (b > 0) ans++;
    if (c > 0) ans++;
    cout << ans << endl;
    if (a != 0) cout << a << " ";
    if (b != 0) cout << b << " ";
    if (c != 0) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << (1LL << 62)<< endl;
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}