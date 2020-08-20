#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;

void encode(int x, int k, vector<pair<int,int>> &v) {
    int ox = x;
    v.clear();
    int p = 2;
    while (p * p <= x) {
        int c = 0;
        while (x % p == 0) {
            x /= p;
            c = (c + 1) % k;
        }
        if (c > 0) v.push_back({p, c});
        p++;
    }
    if (x > 1) {
        v.push_back({x, 1});
    }

    // cout << ox << ": ";
    // for (auto &[p, c] : v) {
    //     cout << p << "," << c << " "; 
    // }
    // cout << endl;
}

bool complement(int k, const vector<pair<int,int>> &v, vector<pair<int,int>> &cv) {
    cv.clear();
    bool same = true;
    for (auto &[p, c] : v) {
        int cc = (k - c) % k;
        same = same && (c == cc);
        if (cc > 0) {
            cv.push_back({p, cc});
        }
    }
    return same;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    map<vector<pair<int,int>>, int> mp;
    vector<pair<int,int>> v;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        encode(x, k, v);
        mp[v]++;
    }
    ll ans = 0;
    for (auto &[key, c] : mp) {
        bool same = complement(k, key, v);
        ll off;
        if (same) {
            off = (c * 1LL * (c-1));
        }
        else {
            off = c * 1LL * mp[v];
        }
        // cout << off << endl;
        ans += off;
    }
    cout << ans / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}