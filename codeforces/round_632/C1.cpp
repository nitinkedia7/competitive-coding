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

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> p(n+1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + v[i-1];
    }
    map<ll, vector<int>> m;
    for (int i = 0; i <= n; i++) {
        m[p[i]].push_back(i);
    }
    ll ans = 0;
    vector<int> v1;
    for (auto x : m) {
        cout << x.first << ": ";
        print(x.second);
    }
    for (auto x : m) {
        v1 = x.second;
        for (int i = 0; i < v1.size(); i++) {
            int j = (i == v1.size()-1 ? n+1 : v1[i+1]);
            ans += (j - v1[i] - 1);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}