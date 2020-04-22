#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        int u = upper_bound(v.begin(), v.end(), 6 * w[i]) - v.begin();
        u--;
        ll nw = (u >= 0 ? v[u] : 0) + w[i];
        if (u == v.size() - 1) v.push_back(nw);
        else if (nw < v[u+1]) v[u+1] = nw;
    }
    cout << "Case #" << t << ": " << v.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}