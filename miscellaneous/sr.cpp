#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 1e5;

ll v[4 * N + 10];
ll lazy[4 * N + 10];
int n;

void build(int start, int end, int node) {
    if (start == end) {
        v[node] = 0; // A[start]
        return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * node);
    build(mid + 1, end, 2 * node + 1);
    v[node] = v[2 * node] + v[2 * node + 1]; 
}

void update(int start, int end, int node, int l, int r, ll val) {
    if (lazy[node] != 0) {
        v[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (l <= start && end <= r) {
        v[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, l, r, val);
    update(mid + 1, end, 2 * node + 1, l, r, val);
    v[node] = v[2 * node] + v[2 * node + 1];
}

ll query(int start, int end, int node, int l, int r) {
    if (lazy[node] != 0) {
        v[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return 0;
    if (l <= start && end <= r) {
        return v[node];
    }
    int mid = (start + end) / 2;
    ll x = query(start, mid, 2 * node, l, r);
    ll y = query(mid + 1, end, 2 * node + 1, l, r);
    return x + y;
}

void sherlock(int t) {
    int q;
    cin >> n >> q;
    for (int i = 0; i < 4 * N + 10; i++) {
        v[i] = 0;
        lazy[i] = 0;
    }
    int qt, l, r, val;
    // build(1, n, 1);
    // cout << "Case " << t << ":" << endl;
    while (q--) {
        cin >> qt >> l >> r;
        if (qt == 0) {
            cin >> val;
            update(1, n, 1, l, r, val);
        }
        else {
            cout << query(1, n, 1, l, r) << endl;
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