#include <bits/stdc++.h>
using namespace std;


void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
} 

void build(vector<int> &v, int n, vector<int> &jew) {
    int l, r;
    for (int i = n - 1; i > 0 ; i--) {
        l = 2 * i;
        r = 2 * i + 1;
        if (jew[v[l]] > jew[v[r]]) {
            v[i] = v[l];
        }
        else {
            v[i] = v[r];
        }
    }
    return;
}

int query(vector<int> &v, int l, int r, int n, vector<int> &jew) {
    assert(l <= r);
    l += n;
    r += n;
    int mvi = -1;
    while (l < r) {
        if (l % 2 == 1) {
            if (mvi == -1 || jew[v[l]] > jew[mvi]) {
                mvi = v[l]; 
            }
        }
        l = (l + 1) / 2;
        if (r % 2 == 1) {
            r--;
            if (mvi == -1 || jew[v[r]] > jew[mvi]) {
                mvi = v[r];
            }
        }
        r /= 2;
    }
    // assert(mvi != -1);
    return mvi;
}

void update(vector<int> &v, int i, int n, vector<int> &jew) {
    jew[i] = -1;
    i = i + n;
    int p = i / 2, l, r;
    while (p > 0) {
        l = 2 * p;
        r = 2 * p + 1;
        if (jew[v[l]] > jew[v[r]]) {
            v[p] = v[l];
        }
        else {
            v[p] = v[r];
        }
        p = p / 2;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    int m, n;
    int l, r;
    while (t--) {
        cin >> m >> n;
        vector<int> jew(n), v(2 * n);
        // v.resize(2 * n);
        // jew.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> jew[i];
            v[i + n] = i;
        }
        // build segtree;
        build(v, n, jew);
        // print(jew);
        // print(v);
        vector<int> count(n, 0);
        while (m--) {
            cin >> l >> r;
            int cd = query(v, l-1, r, n, jew);
            count[cd]++;
        }
        set<pair<int,int>> s;
        for (int i = 0; i < n; i++) {
            
        }
        vector<int> p()
    }
    return 0;
}
