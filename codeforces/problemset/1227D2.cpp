#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;

vector<int> a;
vector<pair<int,int>> v;
vector<tuple<int,int,int>> q;    

void print(vector<pair<int,int>> &v) {
    for (auto &[x, y] : v) {
        cout << -1 * x << "," << y << " ";
    }
    cout << endl;
}

void update(int l, int val, int n, vector<int> &v) {
    l += n;
    v[l] = val;
    l >>= 1;
    while (l > 0) {
        v[l] = v[l << 1] + v[(l << 1) | 1];
        l >>= 1;
    }   
    return;
}

int query(int l, int r, int n, vector<int> &v) {
    l += n;
    r += n;
    int s = 0;
    while (l < r) {
        if (l & 1) {
            s += v[l++];
        }
        if (r & 1) {
            s += v[--r];
        }
        l >>= 1;
        r >>= 1;
    }
    return s;
}

int watson(int k, int p, int &pk, int n, vector<int> &seg) {
    while (pk < k) {
        int pos = v[pk].second;
        update(pos, 1, n, seg);
        pk++;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << seg[i + n] << " ";
    // }
    // cout << endl;
    // now binary search for p
    int l = 0, r = n-1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (query(0, mid+1, n, seg) < p) {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return a[l];
}

void sherlock(int t) {
    int n;
    cin >> n;
    a.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i] = {-1 * a[i], i};
    }
    sort(all(v));
    // print(v);
    int m;
    cin >> m;
    q.resize(m);
    int id = 0;
    for (auto &[k, p, i] : q) {
        cin >> k >> p;
        i = id++;
    }
    sort(all(q));

    vector<int> seg(2 * n, 0);
    vector<int> ans(m);
    int pk = 0;
    for (auto &[k, p, id] : q) {
        ans[id] = watson(k, p, pk, n, seg);
        // cout << k << " " << p << " " << id << " " << ans[id] << endl;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}