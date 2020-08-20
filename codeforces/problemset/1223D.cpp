#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> l(n + 1, -1), r(n + 1);
    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (l[x] == -1) l[x] = i;
        r[x] = i;
    }
    sort(all(v));
    vector<int> u;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i] != v[i-1]) u.push_back(v[i]);
    }
    // Kadane
    int ms = 0, cs = 1;
    for (int i = 0; i < (int) u.size(); i++) {
        if (i < (int) u.size() - 1 && r[u[i]] < l[u[i+1]]) {
            cs++;
        }
        else {
            cs = 1;
        }
        ms = max(ms, cs);
    }
    cout << u.size() - ms << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
