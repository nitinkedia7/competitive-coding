#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;
const int N = 1000;
vector<pair<int,int>> off4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
int X[N][N], Y[N][N], done[N][N];
char B[N][N];


void print2d() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
}


void galactus(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    done[x][y] = 1;
    B[x][y] = 'X';
    int i, j, i1, j1;
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            i1 = i + off4[k].first;
            j1 = j + off4[k].second;
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && !done[i1][j1] && X[i1][j1] == x && Y[i1][j1] == y) {
                done[i1][j1] = 1;
                q.push({i1, j1});
                if (k == 0) B[i1][j1] = 'U';
                else if (k == 1) B[i1][j1] = 'L';
                else if (k == 2) B[i1][j1] = 'D';
                else B[i1][j1] = 'R';
            }   
        }
    }
    return;
}

void strange(int x, int y) {
    // -> <-
    int x1, y1;
    bool trapped = true;
    for (int k = 0; k < 4; k++) {
        x1 = x + off4[k].first;
        y1 = y + off4[k].second;
        if (!(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n)) continue;
        if (X[x1][y1] == -2 && Y[x1][y1] == -2) {
            if (!done[x1][y1]) {
                done[x][y] = 1;
                done[x1][y1] = 1;
                if (k == 0) {
                    B[x][y] = 'D';
                    B[x1][y1] = 'U';
                }
                else if (k == 1) {
                    B[x][y] = 'R';
                    B[x1][y1] = 'L';
                }
                else if (k == 2) {
                    B[x][y] = 'U';
                    B[x1][y1] = 'D';
                }
                else {
                    B[x][y] = 'L';
                    B[x1][y1] = 'R';
                }
            }
            else {
                done[x][y] = 1;
                if (k == 0) {
                    B[x][y] = 'D';
                }
                else if (k == 1) {
                    B[x][y] = 'R';
                }
                else if (k == 2) {
                    B[x][y] = 'U';
                }
                else {
                    B[x][y] = 'L';
                } 
            }
            return;
        }
    }
}

void sherlock(int t) {
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x >> y;
            X[i][j] = x-1;
            Y[i][j] = y-1;   
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            done[i][j] = 0;
            B[i][j] = 'O';
        }
    }
    // handle black holes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!done[i][j] && X[i][j] == i && Y[i][j] == j) {
                galactus(i, j);
            }
        }
    }
    
    // handle infinite loops
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!done[i][j] && X[i][j] == -2 && Y[i][j] == -2) {
                strange(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!done[i][j]) {
                cout << "INVALID" << endl;
                return;
            }
        }
    }
    cout << "VALID" << endl;
    print2d();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}