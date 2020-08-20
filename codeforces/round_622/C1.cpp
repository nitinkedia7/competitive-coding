#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void build(int n, vector<int> &v, vector<ll> &a) {
    for (int i = 0; i < n; i++) {
        v[i + n] = i; 
    }
    for (int i = n-1; i > 0; i--) {
        int l = i << 1, r = (i << 1) | 1;
        if (a[v[l]] < a[v[r]]) {
            v[i] = v[l];
        }
        else {
            v[i] = v[r];
        }
    }
}

int query(int l, int r, int n, vector<int> &v, vector<ll> &a) {
    l += n;
    r += n;
    int mi = v[l];
    while (l < r) {
        if (l & 1) {
            if (a[v[l]] < a[mi]) {
                mi = v[l];
            }
            l++;
        }
        if (r & 1) {
            r--;
            if (a[v[r]] < a[mi]) {
                mi = v[r];
            }
        }
        l >>= 1;
        r >>= 1;
    }
    return mi;
}

ll shortest_first(int l, int r, int n, vector<int> &v, vector<ll> &a) {
    if (l > r) return 0;
    if (l == r) return a[l];
    int p = query(l, r+1, n, v, a);
    ll flat_left = a[p] * (p - l + 1) + shortest_first(p+1, r, n, v, a);
    ll flat_right = shortest_first(l, p-1, n, v, a) + a[p] * (r - p + 1);
    if (flat_left > flat_right) {
        for (int i = l; i <= p; i++) {
            a[i] = a[p];
        }
    }
    else {
        for (int i = p; i <= r; i++) {
            a[i] = a[p]; 
        }
    }
    return max(flat_left, flat_right);
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    vector<int> v(2 * n);
    build(n, v, a);
    shortest_first(0, n-1, n, v, a);    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
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
