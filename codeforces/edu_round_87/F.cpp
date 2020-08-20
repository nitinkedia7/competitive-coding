#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int NINF = -1 * 1e9;

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = 0; j < (int) v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int watson(int n, int k, vector<tuple<int,int,int>> &v, vector<int> &inc, vector<int> &exl) {
    vector<vector<int>> dp(n+1, vector<int> (k + 1, 0));
    vector<vector<int>> par(n+1, vector<int> (k + 1, 0));
    for (int j = 1; j <= k; j++) {
        dp[0][j] = NINF;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int a = get<1> (v[i-1]);
            int b = get<0> (v[i-1]);
            int x = NINF, y = NINF;
            // y: summon and then destroy this minion
            y = dp[i-1][j] + b * 1LL * (k-1);
            if (j > 0) {
                // x : Add to roster
                x = dp[i-1][j-1] + a + b * 1LL * (j-1);
            }
            if (x > y) {
                dp[i][j] = x;
                par[i][j] = 1;
            }
            else {
                dp[i][j] = y;
                par[i][j] = 0;
            }
        }
    }
    // print2d(dp);
    int j = k;
    for (int i = n; i > 0; i--) {
        int x = get<2> (v[i-1]);
        if (par[i][j] == 1) {
            inc.push_back(x);
            j -= 1;
        }
        else if (par[i][j] == 0) {
            exl.push_back(x);
        }
    }
    reverse(all(inc));
    int p = dp[n][k];
    par.clear();
    dp.clear();
    return p;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<tuple<int,int,int>> v(n), v1;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {b, a, i + 1};
    }
    sort(all(v));
    vector<int> inc, exl;
    watson(n, k, v, inc, exl);
    cout << inc.size() + 2 * exl.size() << endl;
    for (int i = 0; i < k - 1; i++) {
        cout << inc[i] << " ";
    }
    for (auto x : exl) {
        cout << x << " " << -x << " ";
    }
    cout << inc.back() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
