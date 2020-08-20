#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 3 * 1e5;

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
    v[node] = max(v[2 * node], v[2 * node + 1]);
}

void update(int start, int end, int node, int l, int r, ll val) {
    if (lazy[node] != 0) {
        v[node] += lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (l <= start && end <= r) {
        v[node] += val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, l, r, val);
    update(mid + 1, end, 2 * node + 1, l, r, val);
    v[node] = max(v[2 * node], v[2 * node + 1]);
}

ll query(int start, int end, int node, int l, int r) {
    if (start > end || start > r || end < l) return INT_MIN;
    if (lazy[node] != 0) {
        v[node] += lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l <= start && end <= r) {
        return v[node];
    }
    int mid = (start + end) / 2;
    ll x = query(start, mid, 2 * node, l, r);
    ll y = query(mid + 1, end, 2 * node + 1, l, r);
    return max(x, y);
}
 
void sherlock(int t) {
    cin >> n;
    vector<int> p(n), q(n);
    vector<int> rp(n+1, -1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        rp[p[i]] = i+1;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    int x = n+1;
    build(1, n, 1);
    for (int i = 0; i < n; i++) {
        // possibly decrease answer
        while (query(1, n, 1, 1, n) <= 0) {
            x--;
            update(1, n, 1, 1, rp[x], 1);
            // for (int j = 1; j <= n; j++) {
            //     update(1, n, 1, j, j, 0);
            // }
            // for (int i = 0; i < 32; i++) {
            //     cout << v[i] << " ";
            // }
            // cout << endl;
        }
        cout << x << " ";
        // place the bomb
        update(1, n, 1, 1, q[i], -1);
        // for (int j = 1; j <= n; j++) {
        //     update(1, n, 1, j, j, 0);
        // }
        // for (int i = 0; i < 32; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl << endl;;
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