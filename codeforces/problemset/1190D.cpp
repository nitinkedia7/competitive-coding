#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

ll find_lr(int x) {
    if (x < 2) return x;
    return x + (x * 1LL * (x - 1)) / 2;
}

void update(int l, int n, vector<int> &v) {
    l += n;
    if (v[l] == 1) return;
    v[l] = 1;
    l = l / 2;
    while (l > 0) {
        v[l]++;
        l /= 2;
    }
    return;
}

int query(int l, int r, int n, vector<int> &v) {
    if (l >= n || l >= r) return 0;
    l += n;
    r += n;
    int ans = 0;
    while (l < r) {
        if (l & 1) {
            ans += v[l++];
        }
        if (r & 1) {
            ans += v[--r];
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void sherlock(int t) {
    int n;
    cin >> n;
    map<int, vector<int>, greater<int>> mpy;
    vector<int> vx(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mpy[y].push_back(x);
        vx[i] = x;
    }
    sort(all(vx));
    map<int,int> mpx;
    int x_index = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || vx[i] != vx[i-1]) {
            mpx[vx[i]] = x_index;
            x_index++;
        }
    }
    ll ans = 0;
    int l, r;
    vector<int> v(2 * x_index);
    for (auto &[y, x_list] : mpy) {
        // cout << y << ": " << endl;
        // for (auto x : x_list) {
        //     cout << x << " ";
        // }
        sort(all(x_list));
        for (auto x : x_list) {
            update(mpx[x], x_index, v);
        }
        int u = query(0, x_index, x_index, v);
        ll x = find_lr(u);
        for (int i = 1; i < (int) x_list.size(); i++) {
            int l = mpx[x_list[i-1]] + 1;
            int r = mpx[x_list[i]];
            u = query(l, r, x_index, v);
            x -= find_lr(u);
        }
        l = 0, r = mpx[x_list[0]];
        x -= find_lr(query(l, r, x_index, v));
        l = mpx[x_list.back()] + 1;
        r = x_index;
        x -= find_lr(query(l, r, x_index, v));
        // cout << y << " " << x << endl;
        ans += x; 
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
