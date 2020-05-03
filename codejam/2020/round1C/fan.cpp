#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int m = s.length();
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'N') {
            y++;
        }
        else if (s[i] == 'S') {
            y--;
        }
        else if (s[i] == 'E') {
            x++;
        }
        else {
            x--;
        }
        int t = abs(x) + abs(y);
        if (t <= i+1) {
            ans = min(ans, i+1);
        }  
    }
    if (ans == INT_MAX) {
        cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    }
    else {
        cout << "Case #" << t << ": " << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
