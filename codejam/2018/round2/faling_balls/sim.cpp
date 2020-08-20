#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

vector<char> m{'.', '\\', '/'};

void sherlock(int t) {
    int r, c;
    cin >> c >> r;
    cout << 1 << endl << c << endl;
    // build
    vector<vector<char>> v(r, vector<char> (c, '.'));
    for (int i = 0; i < r-1; i++) {
        for (int j = 1; j < c-1; j++) {
            if (j == 1 || v[i][j-1] != '\\') {
                int x = rand() % 3;
                v[i][j] = m[x];
            }
            else {
                int x = rand() % 2;
                v[i][j] = m[x];
            }
        }
    }
    // simulate
    vector<int> ans(c);
    for (int j = 0; j < c; j++) {
        int y = j;
        for (int i = 0; i < r; i++) {
            if (v[i][y] == '.') {
                continue;
            }
            else if (v[i][y] == '\\') {
                y++;
            }
            else {
                y--;
            }
        }
        ans[y]++;
    }
    for (int i = 0; i < c; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
