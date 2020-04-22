#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void build(int n, vector<int> &v) {
    for (int i = n-1; i > 0; i--) {
        v[i] = max(v[2 * i], v[2 * i + 1]);
    }
}

int query(int l, int r, int n, vector<int> &v) {
    if (l >= n) return 0;
    l += n;
    r += n;
    int x = v[l];
    while (l < r) {
        if (l & 1) {
            x = max(x, v[l]);
            l++;
        }
        if (r & 1) {
            r--;
            x = max(x, v[r]);
        }
        l = l >> 1;
        r = r >> 1;
    }
    return x;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        v[i] = {-1, b};
    }
    int q;
    cin >> q;
    vector<int> seg(2 * q, 0);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            v[p-1] = {i, x};
        }   
        else {
            assert(t == 2);
            int x;
            cin >> x;
            seg[q + i] = x;
        }
    }
    build(q, seg);
    for (int i = 0; i < n; i++) {
        int l = v[i].first;
        int b = v[i].second;
        b = max(b, query(l+1, q, q, seg));
        cout << b << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}