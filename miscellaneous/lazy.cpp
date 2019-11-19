#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 2e5;

ll v[2*N];
ll d[N];
int n, h;

void apply(int i, int val, int k) {
    v[i] += val * 1LL * k;
    if (i < n) d[i] += val;
}

void push(int i) {
    // push from root to node;
    i += n;
    int s = h, k = 1 << (h-1);
    for (; s > 0; s--) {
        int l = i >> s;
        if (d[l] != 0) {
            apply(2 * l, d[l], k);
            apply(2 * l + 1, d[l], k);
            d[l] = 0;
        }
        k >>= 1;
    }
}

void build(int p) {
    int k = 2;
    p += n;
    while (p > 1) {
        p >>= 1;     
        v[p] = v[2 * p] + v[2 * p + 1] + d[p] * k;
        k <<= 1;
    }
}

ll query(int l, int r) { // [l, r)
    push(l);
    push(r-1);
    ll sum = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            sum += v[l];
            l++;
        }
        if (r & 1) {
            r--;
            sum += v[r];
        }
    }
    return sum;
}

void update(int l, int r, int val) {
    push(l);
    push(r-1);
    int l0 = l, r0 = r;
    int k;
    for (k = 1, l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
        if (l & 1) {
            apply(l, val, k);
            l++;
        }
        if (r & 1) {
            r--;
            apply(r, val, k);
        }
    }
    build(l0);
    build(r0-1);
}

void sherlock(int t) {
    int q;
    cin >> n >> q;
    h = sizeof(int) * 8 - __builtin_clz(n);
    for (int i = 0; i < n; i++) {
        v[n + i] = 0;
        v[i] = 0;
        d[i] = 0;
    }
    int qt, l, r, val;
    cout << "Case " << t << ":" << endl;
    while (q--) {
        cin >> qt >> l >> r;
        if (qt == 0) {
            cin >> val;
            update(l-1, r, val);
        }
        else {
            cout << query(l-1, r) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}