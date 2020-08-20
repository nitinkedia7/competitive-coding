#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll x = 0;
    vector<vector<int>> v(2001, vector<int> (2001));
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            for (int k = 0; k < 10; k++) {
                x++;
            }
            v[i][j] = x;
        }
    }
    for (int i = 0; i < 2001; i++) {
        cout << 0;
    }
    // cout << "Case #" << t << ": " << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}