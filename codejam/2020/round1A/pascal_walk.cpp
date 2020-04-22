#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<vector<int>> v(31, vector<int> (31));

bool check(vector<pair<int,int>> &path, int n) {
    for (int i = 0; i < path.size(); i++) {
        int x = path[i].first-1, y = path[i].second-1;
        if (x < 31) {
            n -= v[x][y];
        }
        else {
            n--;
        }
    }
    // cout << n << endl;
    return n == 0;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<pair<int,int>> path;
    cout << "Case #" << t << ": " << endl;
    if (n <= 30) {
        for (int i = 0; i < n; i++) {
            path.push_back({i+1, 1});
            cout << i+1 << " " << 1 << endl;
        }
        return;
    }
    n -= 30;
    int dir = 0, sum = 0;
    int i;
    for (i = 0; i < 30 && sum < n; i++) {
        if ((n & (1 << i)) == 0) {
            path.push_back({i+1, (dir == 0 ? 1 : i+1)});
            cout << i+1 << " " << (dir == 0 ? 1 : i+1) << endl;
            sum += 1;
        }
        else if (dir == 0) {
            for (int j = 0; j <= i; j++) {
                path.push_back({i+1, j+1});
                cout << i+1 << " " << j+1 << endl;
                sum += v[i][j];
                dir = 1;
            }
        }
        else {
            for (int j = i; j >= 0; j--) {
                path.push_back({i+1, j+1});
                cout << i+1 << " " << j+1 << endl;
                sum += v[i][j];
                dir = 0;
            }
        }
    }
    while (sum < n+30) {
        path.push_back({i+1, (dir == 0 ? 1 : i+1)});
        cout << i+1 << " " << (dir == 0 ? 1 : i+1) << endl;
        sum++;
        i++;
    }
    assert(path.size() <= 500);
    assert(check(path, n + 30));
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    v[0][0] = 1;
    for (int i = 1; i < 31; i++) {
        for (int j = 0; j <= i; j++) {
            v[i][j] = v[i-1][j] + (j > 0 ? v[i-1][j-1] : 0);
        }
    }
    // for (int i = 0; i < 31; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}