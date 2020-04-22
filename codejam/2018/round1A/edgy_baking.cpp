#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<double> wid(100), hei(100);
vector<double> minr(100), maxr(100);
int v[101][50001];
double v1[101][50001];

void reset(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            v[i][j] = 0;
            v1[i][j] = 0;
        }
    }
}

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void peri_range(int i) {
    double w = wid[i], h = hei[i];
    
    double peri = 2 * (w + h);
    minr[i] = 4 * min(w + h / 2, h + w / 2) - peri;
    maxr[i] = 2 * (w + h + sqrt(h * h + w * w)) - peri;
}   

void sherlock(int t) {
    int n;
    double p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> wid[i] >> hei[i];
    }
    double base = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        peri_range(i);
        base += 2 * (wid[i] + hei[i]);
        m += 2 * min(wid[i], hei[i]);
    }
    // Knapsack 100 * (500 * 100)
    reset(n, m);

    v[0][0] = 1; // possible
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            v[i][j] = v[i-1][j];
            v1[i][j] = v1[i-1][j];
            if (j >= minr[i-1] && v[i-1][j - (int)minr[i-1]]) {
                v[i][j] = 1;
                v1[i][j] = max(v1[i][j], v1[i-1][j - (int)minr[i-1]] + maxr[i-1]);
            }
        }
    }
    // print2d(v);
    double ans = 0;
    p -= base;
    for (int j = 0; j <= m; j++) {
        if (v[n][j] == 0) continue;
        if (p >= j && p <= v1[n][j]) ans = p;
        else if (p > v1[n][j]) ans = max(ans, v1[n][j]);
    }
    cout.precision(17);
    cout << "Case #" << t << ": " << fixed  << ans + base << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}