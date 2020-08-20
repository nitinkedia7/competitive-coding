#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N_MAX = 1e6 + 1;

int v[2 * N_MAX];

void build(int n) {
    for (int i = n-1; i > 0; i--) {
        v[i] = v[2 * i] + v[2 * i + 1];
    }
}

bool query(int l, int r, int n, int x) {
    l += n;
    r += n;
    int ans = 0;
    while (l < r) {
        if (l & 1) {
            ans += v[l++];
            if (ans >= x) return false;
        }
        if (r & 1) {
            ans += v[--r];
            if (ans >= x) return false;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans < x;
}

void update(int l, int val, int n) {
    l += n;
    v[l] += val;
    assert(v[l] >= 0);
    int p = l / 2;
    while (p > 0) {
        v[p] = v[p << 1] + v[(p << 1) | 1];
        p >>= 1;
    }
    return;
}

void sherlock(int t) {
    memset(v, 0, sizeof(v));
    int n, q;
    cin >> n >> q;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[n + x]++;
    }
    build(n);
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (x >= 1) {
            update(x, 1, n);
        }
        else if (x < 0) {
            x *= -1;
            int l = 1, r = n, mid;
            while (l <= r) {
                mid = (l + r) / 2;
                if (query(1, mid + 1, n, x)) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            update(l, -1, n);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[i + n] > 0) {
            cout << i << " ";
            // return;
        }
    }
    cout << endl;
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
