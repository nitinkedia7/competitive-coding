#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

bool check(vector<vector<int>> &v, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i-2 >= 0 && j >= 0) assert(v[i-2][j] != v[i][j]);
            if (i+2 < n  && j >= 0) assert(v[i+2][j] != v[i][j]);
            if (i >= 0 && j-2 >= 0) assert(v[i][j-2] != v[i][j]);
            if (i >= 0 && j+2 < m ) assert(v[i][j+2] != v[i][j]);
            if (i-1 >= 0 && j-1 >= 0) assert(v[i-1][j-1] != v[i][j]);
            if (i-1 >= 0 && j+1 < m) assert(v[i-1][j+1] != v[i][j]);
            if (i+1 < n && j-1 >= 0) assert(v[i+1][j-1 != v[i][j]]);
            if (i+1 < n && j+1 < m) assert(v[i+1][j+1] != v[i][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int> (m, 0));
        vector<int> color(5, 1);
        int r = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // reset then cross 1 to r
                for (int k = 1; k <= r; k++) {
                    color[k] = 1;
                }
                if (i-2 >= 0 && j >= 0) color[v[i-2][j]] = 0;
                if (i+2 < n  && j >= 0) color[v[i+2][j]] = 0;
                if (i >= 0 && j-2 >= 0) color[v[i][j-2]] = 0;
                if (i >= 0 && j+2 < m ) color[v[i][j+2]] = 0;
                if (i-1 >= 0 && j-1 >= 0) color[v[i-1][j-1]] = 0;
                if (i-1 >= 0 && j+1 < m) color[v[i-1][j+1]] = 0;
                if (i+1 < n && j-1 >= 0) color[v[i+1][j-1]] = 0;
                if (i+1 < n && j+1 < m) color[v[i+1][j+1]] = 0;

                for (int k = 1; k <= r; k++) {
                    if (color[k] == 1) {
                        v[i][j] = k;
                        break;
                    }
                    if (k == r) {
                        r++;
                        v[i][j] = r;
                        break;
                    }
                }                    
            }
        }
        if (r < 4) {
            check(v, n, m);
            cout << r << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    // assert(v[i][j] > 0);
                    cout << v[i][j];
                    if (j != m-1) cout << " ";
                }
                cout << endl;
            }
        }
        else {
            vector<vector<int>> x(n, vector<int> (m, 0));
            cout << 4 << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i % 4 == 0) {
                        if (j % 4 == 0) x[i][j] = 1;
                        if (j % 4 == 1) x[i][j] = 1;
                        if (j % 4 == 2) x[i][j] = 2;
                        if (j % 4 == 3) x[i][j] = 2;
                    }
                    if (i % 4 == 2) {
                        if (j % 4 == 0) x[i][j] = 2;
                        if (j % 4 == 1) x[i][j] = 2;
                        if (j % 4 == 2) x[i][j] = 1;
                        if (j % 4 == 3) x[i][j] = 1;  
                    }
                    if (i % 4 == 1) {
                        if (j % 4 == 0) x[i][j] = 3;
                        if (j % 4 == 1) x[i][j] = 3;
                        if (j % 4 == 2) x[i][j] = 4;
                        if (j % 4 == 3) x[i][j] = 4;
                    }
                    if (i % 4 == 3) {
                        if (j % 4 == 0) x[i][j] = 4;
                        if (j % 4 == 1) x[i][j] = 4;
                        if (j % 4 == 2) x[i][j] = 3;
                        if (j % 4 == 3) x[i][j] = 3;  
                    }
                    // if (j != m-1) cout << " ";
                }
                // cout << endl;
            }
            check(x, n, m);
        }
    }
    return 0;
}