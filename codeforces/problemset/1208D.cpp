#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N = 2 * 1e5;

ll s[N + 1];
pair<ll,int> v[4 * N + 10];
ll lazy[4 * N + 10];
int n;

pair<ll,int> find_less(pair<ll,int> l, pair<ll,int> r) {
    if (l.first < r.first) {
        return l;
    }
    return r;
}

void build(int start, int end, int node) {
    if (start == end) {
        // cout << start << endl;
        v[node] = {s[start], start};
        return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * node);
    build(mid + 1, end, 2 * node + 1);
    v[node] = find_less(v[2 * node], v[2 * node + 1]);    
}

void update(int start, int end, int node, int l, int r, ll val) {
    // if (l > r) return;
    // Deduct val from s[i] of [l, r]
    if (lazy[node] != 0) {
        v[node].first -= lazy[node];
        // v[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (l <= start && end <= r) {
        v[node].first -=  val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, l, r, val);
    update(mid + 1, end, 2 * node + 1, l, r, val);
    v[node] = find_less(v[2 * node], v[2 * node + 1]);    
}

pair<ll,int> query(int start, int end, int node, int l, int r) {
    if (lazy[node] != 0) {
        v[node].first -= lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return {LLONG_MAX, 0};
    if (l <= start && end <= r) {
        return v[node];
    }
    int mid = (start + end) / 2;
    pair<ll,int> x = query(start, mid, 2 * node, l, r);
    pair<ll,int> y = query(mid + 1, end, 2 * node + 1, l, r);
    return find_less(x, y);
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i].first << "," << v[i].second << "  ";
    }
    cout << endl;
}

void sherlock(int t) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    build(1, n, 1);
    // print(40);
    vector<int> p(n + 1);
    pair<ll,int> x;
    for (int i = 1; i <= n; i++) {
        // find position of i
        x = query(1, n, 1, 1, n);
        // cout << x.first << "," << x.second << endl; 
        // print(40);
        p[x.second] = i;
        update(1, n, 1, x.second, x.second, N * 1LL * N - LLONG_MAX);
        update(1, n, 1, x.second + 1, n, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
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
