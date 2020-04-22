#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> s(k), e(k);
    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        x--;
        y--;
        s[i] = {x, y};
    }
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        x--;
        y--;
        e[i] = {x, y};
    }
    cout << n + m + n * m - 1 << endl;
    for (int i = 0; i < n; i++) {
        cout << 'U';
    }
    for (int i = 0; i < m; i++) {
        cout << 'L';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cout << (i % 2 == 0 ? 'R' : 'L');
        }
        if (i < n-1) {
            cout << 'D';
        }
    }
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