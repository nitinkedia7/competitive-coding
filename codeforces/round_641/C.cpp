#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void process(map<int,vector<int>> &mp, int x) {
    int p = 2;
    while (p * p <= x) {
        int c = 0;
        while (x % p == 0) {
            c++;
            x /= p;
        }
        if (c > 0) mp[p].push_back(c);
        p++;
    }
    if (x > 1) mp[x].push_back(1);
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        process(mp, v[i]);
    }   
    // for (auto &[p, a] : mp) {
    //     cout << p << ": ";
    //     for (auto x : a) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    ll g = 1;
    for (auto &[p, a] : mp) {
        sort(all(a));
        int l = a.size();
        if (l <= n - 2) {
            // nothing
        } 
        else if (l == n-1) {
            for (int i = 0; i < a[0]; i++) {
                g *= p;
            }
        }
        else {
            int c = a[1];
            for (int i = 0; i < c; i++) {
                g *= p;
            }
        }
    }
    cout << g << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
