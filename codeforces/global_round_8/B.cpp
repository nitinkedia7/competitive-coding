#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const string str = "codeforces";

struct Compare {
    bool operator()(const pair<ll,int> &p, const pair<ll,int> &q) const {
        // ll x = p.first, y = q.first;
        return !((p.first + 1) * q.first < (q.first + 1) * p.first);
    }
};

void sherlock(int t) {
    ll k;
    cin >> k;
    ll ck = 1, l = 10;
    set<pair<ll,int>, Compare> s;
    for (int i = 0; i < 10; i++) {
        s.insert({1, i});
    }
    vector<int> v(10, 1);
    ll x, i;
    while (ck < k) {
        x = s.begin()->first;
        i = s.begin()->second;
        s.erase(s.begin());
        ck /= x;
        ck *= (x + 1);
        v[i]++;
        l++;
        s.insert({x + 1, i});
    }
    // cout << l << endl;
    ll ans = 1;
    for (int i = 0; i < 10; i++) {
        ans *= v[i];
    }
    assert(ans >= k);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << str[i];
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
