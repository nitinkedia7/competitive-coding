#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int find(int x, int y, vector<int> &v, vector<vector<int>> &p) {
    int ml = 0;
    for (int i = 1; i <= 26; i++) {
        ml = max(ml, p[i][y] - (x > 0 ? p[i][x-1] : 0));
    }
    int n = v.size();
    int sl = 0;
    for (int i = 1; i <= 26; i++) {
        int left = x > 0 ? p[i][x-1] : 0;
        int right = p[i][n-1] - p[i][y];
        sl = max(sl, min(left, right));
    }
    // cout << x << " " << y << " " << ml << " " << sl << endl;
    return ml + 2 * sl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> p(27, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p[v[i]][i] = 1;
    }
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j < n; j++) {
            p[i][j] += p[i][j-1];
        }
    }
    int x = 0;
    for (int i = 1; i <= 26; i++) {
        x = max(x, p[i][n-1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            x = max(x, find(i, j, v, p));
        }
    }
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}