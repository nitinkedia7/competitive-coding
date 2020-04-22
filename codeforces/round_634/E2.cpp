#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<int> v(2e5 + 1);
vector<vector<int>> p(201, vector<int> (2e5 + 1));

int find(int x, int y) {
    if (x > y) return 0;
    int m = 0;
    for (int i = 1; i <= 200; i++) {
        m = max(m, p[i][y] - (x > 0 ? p[i][x-1] : 0));
    }
    return m;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> pos(201);
    for (int i = 1; i <= 200; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p[v[i]][i] = 1;
        pos[v[i]].push_back(i);
    }
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j < n; j++) {
            p[i][j] += p[i][j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 200; i++) {
        // cout << i << " " << p[i][n-1] << endl;
        ans = max(ans, p[i][n-1]);
    }
    // cout << endl;

    for (int i = 1; i <= 200; i++) {
        int l = 0, r = pos[i].size() - 1;
        while (l < r) {
            int x = pos[i][l];
            int y = pos[i][r];
            if (x+1 > y-1) break;
            ans = max(ans, find(x+1, y-1) + 2 * (l+1));
            l++;
            r--;
        }
    }
    pos.clear();
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}