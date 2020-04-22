#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

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

bool is_round_up(int m, int n) {
    double r1 = m;
    r1 /= n;
    r1 *= 100;
    double r2 = r1 + 0.5;
    int x1 = r1, x2 = r2;
    return x2 > x1;
}

void sherlock(int t) {
    int n, l;
    cin >> n >> l;
    vector<int> c(l);
    for (int i = 0; i < l; i++) {
        cin >> c[i];
    }
    
    vector<int> rounds_up(n + 1);
    for (int i = 0; i <= n; i++) {
        rounds_up[i] = is_round_up(i, n);
    }
    vector<int> jr(n + 1);
    int x = INT_MAX;
    for (int i = n; i >= 0; i--) {
        if (rounds_up[i]) x = i;
        jr[i] = x;
    }
    // print(jr);
    vector<pair<int,int>> v;
    for (int i = 0; i < l; i++) {
        v.push_back({jr[c[i]] - c[i], c[i]});
    }
    for (int i = 0; i < n; i++) {
        v.push_back({jr[0] - 0, 0});
    }
    sort(v.begin(), v.end());
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i].first << "," << v[i].second << " ";
    // }
    // cout << endl;
    int g = n;
    for (int i = 0; i < l; i++) g -= c[i];
    int i = 0;
    x = 0;
    int ans = 0;
    double z;
    while (x < n && i < n + l) {
        if (g >= v[i].first) {
            g -= v[i].first;
            x += v[i].second + v[i].first;
            z = ((v[i].second + v[i].first) * 100.00) / n;
            z += 0.5;
            ans += z;
        }
        else { // no gift required
            x += v[i].second;
            z = (v[i].second * 100.00) / n;
            z += 0.5;
            ans += z;
        }
        // cout << x << endl;
        i++;
    }
    if (x < n) {
        z = ((n - x) * 100.00) / n;
        z += 0.5;
        ans += z;
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}