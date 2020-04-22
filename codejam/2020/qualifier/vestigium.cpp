#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int v[100][100];

void reset(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = 0;
    }
}

void sherlock(int t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int tr = 0;
    for (int i = 0; i < n; i++) {
        tr += v[i][i];
    }
    // check row repeat
    vector<int> rep(n + 1);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        reset(rep);
        for (int j = 0; j < n; j++) {
            if (rep[v[i][j]]) {
                x++;
                break;
            }
            rep[v[i][j]] = 1;
        }
    }
    for (int j = 0; j < n; j++) {
        reset(rep);
        for (int i = 0; i < n; i++) {
            if (rep[v[i][j]]) {
                y++;
                break;
            }
            rep[v[i][j]] = 1;
        }
    }
    cout << "Case #" << t << ": ";
    cout << tr << " " << x << " " << y << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}