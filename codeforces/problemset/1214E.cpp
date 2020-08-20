#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = 2 * i;
    }    
    sort(all(v), greater<pair<int,int>>());
    vector<int> r(n);
    r[0] = v[0].second;
    for (int i = 1; i < n; i++) {
        r[i] = v[i].second;
        cout << r[i-1] + 1 << " " << r[i] + 1 << endl; 
    }
    for (int i = 0; i < n; i++) {
        int x = v[i].second + 1;
        int j = i + v[i].first - 1;
        if (j == (int) r.size() - 1) {
            r.push_back(x);
        }
        cout << r[j] + 1 << " " << x+1 << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
