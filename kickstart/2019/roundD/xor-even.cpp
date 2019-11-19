#include <bits/stdc++.h>
using namespace std;

void build(vector<pair<int,int>> &segtree, int n) {
    // n = N
    int v;
    for (int i = n - 1; i > 0; i--) {
        v = segtree[2 * i].first ^ segtree[2 * i + 1].first;
        segtree[i] = {v, segtree[2 * i].second + segtree[2 * i + 1].second};
    }
    return;
}

void update(vector<pair<int,int>> &segtree, int n, int p, int v) {
    p += n;
    segtree[p] = {v, 1};
    p = p >> 1;
    int x;
    while (p > 0) {
        x = segtree[2 * p].first ^ segtree[2 * p + 1].first;
        segtree[p] = {x, segtree[2 * p].second + segtree[2 * p + 1].second};
        p = p >> 1; 
    }
    return;
}

bool isEven(int v) {
    bool even = true;
    while (v > 0) {
        if (v % 2) even = !even;
        v /= 2;
    }
    return even;
}

bool isLeaf(int r, int n) {
    return n <= r && r < 2 * n;
}

int largesteven(vector<pair<int,int>> &segtree, int n, int r) {
    if (isEven(segtree[r].first)) {
        return segtree[r].second;
    }
    if (isLeaf(r, n)) return 0;
    int lc = 2 * r, rc = 2 * r + 1;
    int ans1, ans2;
    if (!isEven(segtree[lc].first)) {
        ans1 = segtree[lc].second;
        // left child is odd find just right odd child
        while (!isLeaf(rc, n) && isEven(segtree[rc].first)) {
            rc = 2 * rc; // continue down left
        }
        if (!isEven(segtree[rc].first)) ans1 += segtree[rc].second;
        else ans1 = 0;
        ans2 = segtree[rc].second;
        while (!isLeaf(lc, n) && !isEven(segtree[lc].first)) {
            lc = 2 * lc + 1;
        }
        if (isEven(segtree[lc].first)) ans2 += segtree[lc].second;
        else ans2 = 0;
        return max(ans1, ans2);
    }
    else {
        ans1 = segtree[lc].second;
        // left child is even find just right even child
        while (!isLeaf(rc, n) && !isEven(segtree[rc].first)) {
            rc = 2 * rc; // continue down left
        }
        if (isEven(segtree[rc].first)) ans1 += segtree[rc].second;
        else ans1 = 0;
        // 2nc cand: right child must be odd. find just left odd child
        ans2 = segtree[rc].second;
        while (!isLeaf(lc, n) && isEven(segtree[lc].first)) {
            lc = 2 * lc + 1;
        }
        if (!isEven(segtree[lc].first)) ans2 += segtree[lc].second;
        else ans2 = 0;
        return max(ans1, ans2);
    }
} 

void print(vector<pair<int,int>> &segtree) {
    for (int i = 0; i < segtree.size(); i++) {
        cout << segtree[i].first << "," << segtree[i].second << " ";
    }
    cout << endl;
}

void onacase(int t) {
    int n, q;
    cin >> n >> q;
    int N = 1;
    while (N < n) {
        N = N << 1;
    }
    vector<pair<int,int>> segtree(2 * N);
    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        segtree[N + i] = {v, 1};
    }
    // padding has no value
    for (int i = N + n; i < 2 * N; i++) {
        segtree[i] = {0, 0};
    }
    build(segtree, N);
    // print(segtree);
    // process queries;
    cout << "Case #" << t << ": ";
    int p;
    for (int i = 0; i < q; i++) {
        cin >> p >> v;
        update(segtree, N, p, v);
        print(segtree);
        // find largest interval
        cout << largesteven(segtree, N, 1) << " ";
    }
    cout << endl;
    segtree.clear();
}

int main() {
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        onacase(t);
    }
}