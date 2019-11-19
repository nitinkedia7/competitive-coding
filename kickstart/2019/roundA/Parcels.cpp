#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &v, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dist) {
    vector<vector<int>> color(r, vector<int> (c));
    queue<tuple<int,int,int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j]) {
                q.push({i, j, 0});
                color[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        int i = get<0> (q.front());
        int j = get<1> (q.front());
        int l = get<2> (q.front());
        dist[i][j] = l;
        q.pop();
        if (i > 0 && color[i-1][j] == 0) {
            color[i-1][j] = 1;
            q.push({i-1, j, l + 1});
        }
        if (i < r - 1 && color[i+1][j] == 0) {
            color[i+1][j] = 1;
            q.push({i+1, j, l + 1});
        }
        if (j > 0 && color[i][j-1] == 0) {
            color[i][j-1] = 1;
            q.push({i, j-1, l + 1});
        }
        if (j < c - 1 && color[i][j+1] == 0) {
            color[i][j+1] = 1;
            q.push({i, j+1, l + 1});
        }
        color[i][j] = 2;
    }
    color.clear();
    return;
}

vector<int> manhattan(vector<vector<int>> &dist, int r, int c, int k) {
    vector<int> v = {INT_MIN, INT_MAX, INT_MIN, INT_MAX};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dist[i][j] > k) {
                v[0] = max(v[0], i + j);
                v[1] = min(v[1], i + j);
                v[2] = max(v[2], i - j);
                v[3] = min(v[3], i - j);
            }
        }
    }
    return v;
}

bool canbedone(vector<vector<int>> &dist, int r, int c, int k) {
    vector<int> opt = manhattan(dist, r, c, k);
    if (opt[0] == INT_MIN) return true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int k1 = INT_MIN;
            k1 = max(k1, abs(opt[0] - i - j));
            k1 = max(k1, abs(opt[1] - i - j));
            k1 = max(k1, abs(opt[2] - i + j));
            k1 = max(k1, abs(opt[3] - i + j));
            if (k1 <= k) return true;
        }
    }
    return false;
}

void sherlock(int t) {
    int r, c;
    cin >> r >> c;
    char z;
    vector<vector<int>> grid(r, vector<int> (c));
    vector<vector<int>> dist(r, vector<int> (c)); 

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> z;
            grid[i][j] = z - '0';
        }
    }

    bfs(r, c, grid, dist);
    // print(dist, r, c);
    int s = 0, e = r + c - 1;
    while (s <= e) {
        int k = (s + e) / 2;
        if (!canbedone(dist, r, c, k)) {
            s = k + 1;
        } 
        else e = k - 1;
    }
    cout << "Case #" << t << ": " << s << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}