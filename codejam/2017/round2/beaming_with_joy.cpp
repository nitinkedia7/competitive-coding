#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int R_C_MAX = 50; 
const int D = 4;

int r, c;
char v[R_C_MAX][R_C_MAX];
int ray_vis[D][R_C_MAX][R_C_MAX], cell_vis[R_C_MAX][R_C_MAX];
vector<pair<int,int>> off4 = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void pass_cell(int &x, int &y, int &d) {
    // Ray from {x, y} in direction d;
    assert(d >= 0 && d < 4);
    x += off4[d].first;
    y += off4[d].second;
    if (v[x][y] == '#') {
        d = -1;
    }
    else if (v[x][y] == '/') {
        if (d == 0) d = 1;
        else if (d == 1) d = 0;
        else if (d == 2) d = 3;
        else d = 2;
    }
    else if (v[x][y] == '\\') {
        if (d == 0) d = 3;
        else if (d == 1) d = 2;
        else if (d == 2) d = 4;
        else d = 0;
    } 
    return;
}

void ray_simulator(int x, int y, int d) {
    // TODO restrictions on x, y
    while (x >= 0 && x < r && y >= 0 && y < c && d >= 0 && d < 4 && ray_vis[d][x][y] == 0) {
        ray_vis[d][x][y] = 1;
        pass_cell(x, y, d);
        cell_vis[x][y] = 1;
    }    
}

bool protect(int x, int y) {
    // -
    int row = 1, col = 1; 
    memset(ray_vis, 0, sizeof(ray_vis));
    memset(cell_vis, 0, sizeof(cell_vis));
    ray_simulator(x, y, 1);
    ray_simulator(x, y, 3);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cell_vis[i][j] && (v[i][j] == '-' || v[i][j] == '|')) {
                row = 0;
                break;
            }
        }
    }
    // |
    memset(ray_vis, 0, sizeof(ray_vis));
    memset(cell_vis, 0, sizeof(cell_vis));
    ray_simulator(x, y, 0);
    ray_simulator(x, y, 2);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cell_vis[i][j] && (v[i][j] == '-' || v[i][j] == '|')) {
                col = 0;
                break;
            }
        }
    }
    // 
}

void sherlock(int t) {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    
    cout << "Case #" << t << ": POSSIBLE" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[i][j];
        }
        cout << endl;
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
