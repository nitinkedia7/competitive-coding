#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll x, y;
    cin >> x >> y;
    char X = (x >= 0 ? 'E' : 'W');
    char NX = (x >= 0 ? 'W' : 'E');
    char Y = (y >= 0 ? 'N' : 'S');
    char NY = (y >= 0 ? 'S' : 'N');

    x = abs(x);
    y = abs(y);

    string ans;
    for (int i = 0; i < 31; i++) {
        // cout << x << " " << y << endl;
        if (x == 1 && y == 0) {
            ans += X;
            x--;
        }
        else if (x == 0 && y == 1) {
            ans += Y;
            y--;
        }
        if (x == 0 && y == 0) break;

        int bx = x & 1;
        int by = y & 1;
        if (bx == by) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            return;
        }
        if (bx == 1 && by == 0) {
            int nbx = (x & 2) / 2;
            int nby = (y & 2) / 2;
            if (nbx == 1 && nby == 1) {
                ans += NX;
                x++;
            }
            else if (nbx == 0 && nby == 1) {
                ans += X;
                x--;
            }
            else if (nbx == 1 && nby == 0) {
                ans += X;
                x--;
            }
            else if (nbx == 0 && nby == 0) {
                ans += NX;
                x++;
            }
        }
        else if (bx == 0 && by == 1) {
            int nbx = (x & 2) / 2;
            int nby = (y & 2) / 2;
            if (nbx == 1 && nby == 1) {
                ans += NY;
                y++;
            }
            else if (nbx == 0 && nby == 1) {
                ans += Y;
                y--;
            }
            else if (nbx == 1 && nby == 0) {
                ans += Y;
                y--;
            }
            else if (nbx == 0 && nby == 0) {
                ans += NY;
                y++;
            }
        }
        x /= 2;
        y /= 2;
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}