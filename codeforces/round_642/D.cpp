#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    set<pair<int,int>, greater<pair<int,int>>> s;
    s.insert({n, 0});
    int len, l;
    for (int i = 0; i < n; i++) {
        len = s.begin()->first;
        l = -1 * s.begin()->second;
        s.erase(s.begin());
        if (len % 2 == 1) {
            v[l + (len / 2)] = i+1;
            if (len / 2 > 0) {
                s.insert({len / 2, -1 * l});
                s.insert({len / 2, -1 * (l + len / 2 + 1)});
            }
        }
        else {
            int x = l + (len - 1) / 2;
            v[x] = i+1;
            if (x - l > 0) {
                s.insert({x-l, -1 * l});
            }
            int r = l + len - 1;
            if (r - x > 0) {
                s.insert({r - x, -1 * (x + 1)});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
