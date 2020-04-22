#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int x = *max_element(c.begin() + l, c.begin() + r + 1);
            int y = *max_element(d.begin() + l, d.begin() + r + 1);
            if (abs(x - y) <= k) ans++;
        }
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