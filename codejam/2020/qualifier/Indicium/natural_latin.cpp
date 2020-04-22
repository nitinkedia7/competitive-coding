
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int v[5][5], row[5][5], col[5][5];
map<pair<int,int>, vector<vector<int>>> m; 

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

void fill(int x, int y, int n, int &ctr) {
    if (x == n && y == 0) {
        if (m.find({n, ctr}) == m.end()) {
            vector<vector<int>> v1(n, vector<int> (n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    v1[i][j] = v[i][j];
                }
            }
            m.insert({{n, ctr}, v1});
            // print(n, v1);
        }
        return;
    }
    int nx, ny;
    for (int i = 1; i <= n; i++) {
        if (row[x][i] == 0 && col[y][i] == 0) {
            row[x][i] = 1;
            col[y][i] = 1;
            v[x][y] = i;
            nx = x;
            ny = y + 1;
            if (ny == n) {
                ny = 0;
                nx++;
            };
            if (x == y) ctr += i;
            fill(nx, ny, n, ctr);
            row[x][i] = 0;
            col[y][i] = 0;
            if (x == y) ctr -= i;
        }
    }
} 


void sherlock(int t) {
    int n, tr;
    cin >> n >> tr;
    cout << "Case #" << t << ": ";
    if (m.find({n, tr}) == m.end()) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << "POSSIBLE" << endl;
        print(n, m[{n, tr}]);
    }
    return;
}

int main() {
    // srand(unsigned(time(0)));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int n = 2; n <= 5; n++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = 0;
                row[i][j] = 0;
                col[i][j] = 0;
            }
        }
        int ctr = 0;
        fill(0, 0, n, ctr);
    }
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}