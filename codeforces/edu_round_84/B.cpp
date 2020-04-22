#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    int k, p;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> p;
            v[i].push_back(p-1);
        }
    }
    vector<int> pr(n), da(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (pr[v[i][j]] == 0) {
                pr[v[i][j]] = 1;
                da[i] = 1;
                break;
            }
        }
    }
    int d;
    for (d = 0; d < n; d++) {
        if (da[d] == 0) break;
    }
    for (p = 0; p < n; p++) {
        if (pr[p] == 0) break;
    }
    if (d == n) {
        cout << "OPTIMAL" << endl;
    }
    else {
        cout << "IMPROVE" << endl;
        cout << d+1 << " " << p+1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}