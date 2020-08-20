#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int MAXN = 1000;

int n, m, t;
char v[MAXN][MAXN];
int vis[MAXN][MAXN], f[MAXN][MAXN], dist[MAXN][MAXN];
vector<int> forest_size;
vector<pair<int,int>> off4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void print2d() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << f[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int x, int y, int fi, int &s) {
    s++;
    vis[x][y] = 1;
    f[x][y] = fi;
    for (int k = 0; k < 4; k++) {
        int vx = x + off4[k].first;
        int vy = y + off4[k].second;
        if (valid(vx, vy) && !vis[vx][vy] && v[x][y] == v[vx][vy]) {
            dfs(vx, vy, fi, s);
        }
    }
    vis[x][y] = 2;
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
            int fid = f[i][j];
            if (forest_size[fid] > 1) {
                dist[i][j] = 0;
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int vx = x + off4[k].first;
            int vy = y + off4[k].second;
            if (valid(vx, vy) && !vis[vx][vy]) {
                dist[vx][vy] = 1 + dist[x][y];
                vis[vx][vy] = 1;
                q.push({vx, vy}); 
            } 
        }
    }
    return;
}

void sherlock(int tc) {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    memset(vis, 0, sizeof(v));
    int fi = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            int s = 0;
            dfs(i, j, fi, s);
            forest_size.push_back(s);
            fi++;
        }
    }  
    bfs();
    // print2d();
    ll x, y, p;
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> p;
        x--;
        y--;
        // cout << x << "," << y << " ";
        if (dist[x][y] == -1) {
            cout << v[x][y] << endl;
        }
        else if (p <= dist[x][y]) {
            cout << v[x][y] << endl;
        }
        else {
            int base = v[x][y] - '0';
            cout << (base + p - dist[x][y]) % 2 << endl;
        }
    }   
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}