#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

void sherlock(int t) {
    int n, k, x;
    cin >> n >> k;
    vector<int> v;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > n-k) {
            sum += x;
            v.push_back(i);
        }
    }
    ll p = 1;
    for (int i = 0; i < v.size()-1; i++) {
        p *= (v[i+1] - v[i]);
        p %= MOD;
    }
    cout << sum << " " << p << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}