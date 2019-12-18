#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    int l = to_string(n).length();
    int ans = 9 * (l - 1);
    int x = 0;
    for (int i = 0; i < l; i++) {
        x *= 10;
        x += 1;
    }   
    int y = x;
    while (x <= n) {
        ans++;
        x += y;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}