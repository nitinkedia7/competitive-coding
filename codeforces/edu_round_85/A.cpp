#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int p, c;
    for (int i = 0; i < n; i++) {
        cin >> p >> c;
        v[i] = {p, c};
    }
    p = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first < p || v[i].second < c) {
            cout << "NO" << endl;
            return;
        }
        if (v[i].second - c > v[i].first - p) {
            cout << "NO" << endl;
            return;
        } 
        p = v[i].first;
        c = v[i].second;
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}