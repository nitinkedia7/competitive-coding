#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int v[50][50], row[50][50], col[50][50];

void print(int n, vector<vector<int>> &v) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }
    // cout << endl;
}

void fill(int x, int y, int n, int tr, int &ctr, bool &done, vector<vector<int>> &v1, vector<vector<vector<int>>> &ord) {
    if (x == n && y == 0) {
        // print(n);
        if (ctr == tr) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    v1[i][j] = v[i][j];
                }
            }
            done = true;
        }
        return;
    }
    // random_shuffle(ord[x][y].begin(), ord[x][y].end());
    int nx, ny;
    for (int j = 1; j <= n; j++) {
        int i = ord[x][y][j];
        if (x == y && ctr + i > tr) continue; 
        if (row[x][i] == 0 && col[y][i] == 0) {
            row[x][i] = 1;
            col[y][i] = 1;
            v[x][y] = i;
            // (x, y) -> (x, y + 1)
            nx = x;
            ny = y + 1;
            if (ny == n) {
                ny = 0;
                nx++;
            };
            if (x == y) ctr += i;
            fill(nx, ny, n, tr, ctr, done, v1, ord);
            // if (done) break;
            row[x][i] = 0;
            col[y][i] = 0;
            if (x == y) ctr -= i;
        }
        if (done) break;
    }
} 

void sherlock(int t) {
    int n, tr;
    cin >> n >> tr;
    // cout << n << " " << tr << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = 0;
            row[i][j] = 0;
            col[i][j] = 0;
        }
    }
    int ctr = 0;
    bool done = false;
    vector<vector<int>> v1(n, vector<int> (n));
    vector<vector<vector<int>>> ord(n, vector<vector<int>> (n, vector<int> (n)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ord[i][j][k] = k + 1;
            }
        }
    }
    fill(0, 0, n, tr, ctr, done, v1, ord);
    cout << "Case #" << t << ": ";
    if (!done) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << "POSSIBLE" << endl;
        print(n, v1);
    }
    return;
}

int main() {
    srand(unsigned(time(0)));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}