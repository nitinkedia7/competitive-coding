#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int c;
    cin >> c;
    vector<int> v(c);
    for (int i = 0; i < c; i++) {
        cin >> v[i];
    } 
    // reverse(all(v));   
    if (v[0] == 0 || v[c-1] == 0) {
        cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> target(c);
    int x = 0;
    for (int j = 0; j < c; j++) {
        int z = v[j];
        while (z > 0) {
            target[x] = j;
            x++;
            z--;
        }
    }
    // for (int i = 0; i < c; i++) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < c; i++) {
    //     cout << target[i] << " ";
    // }
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < c; i++) {
        int j = target[i];
        ans = max(ans, abs(j - i));
    }
    ans++;
    cout << "Case #" << t << ": " << ans << endl; 
    vector<vector<char>> grid(ans, vector<char> (c, '.'));
    for (int i = 0; i < c; i++) {
        int j = target[i], d = abs(j - i);
        if (i <= j) {
            for (int k = 0; k < d; k++) {
                grid[ans - (d-k) - 1][i+k] = '\\';
            }
        }
        else {
            for (int k = 0; k < d; k++) {
                grid[ans - (d-k) - 1][i-k] = '/';
            }
        }
    }
    for (int i = 0; i < ans; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j];
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
