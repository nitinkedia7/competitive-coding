#include <bits/stdc++.h>
using namespace std;

struct node {
    int length, oddleft, oddright, evenleft, evenright, oddbtw, evenbtw;
};

node* combine(node *l, node *r) {
    // length, odd left, odd right, even left, even right, odd b/w, even btw
    node *root = new node();
    root->length = l->length + r->length;
    int x, y;
    // oddleft
    x = l->oddleft + (l->oddleft && l->oddleft == l->length ? r->evenleft : 0);
    y = l->evenleft && l->evenleft == l->length && r->oddleft ? l->evenleft + r->oddleft : 0;
    root->oddleft = max(x, y);
    // oddright
    x = r->oddright + (r->oddright && r->oddright == r->length ? l->evenright : 0);
    y = r->evenright && r->evenright == r->length && l->oddright ? r->evenright + l->oddright : 0;
    root->oddright = max(x, y);
    // evenleft
    x = l->evenleft + (l->evenleft && l->evenleft == l->length ? r->evenleft : 0);
    y = l->oddleft && l->oddleft == l->length && r->oddleft ? l->oddleft + r->oddleft : 0;
    root->evenleft = max(x, y);
    // evenright
    x = r->evenright + (r->evenright && r->evenright == r->length ? l->evenright : 0);
    y = r->oddright && r->oddright == r->length && l->oddright ? r->oddright + l->oddright : 0;
    root->evenright = max(x, y);
    // oddbtw
    x = l->oddright ? l->oddright + r->evenleft : 0;
    y = r->oddleft ? l->evenright + r->oddleft : 0;
    root->oddbtw = max(x, y);
    root->oddbtw = max(root->oddbtw, l->oddbtw);
    root->oddbtw = max(root->oddbtw, r->oddbtw);
    // evenbtw
    x = l->evenright + r->evenleft;
    y = l->oddright && r->oddleft ? l->oddright + r->oddleft : 0;
    root->evenbtw = max(x, y);
    root->evenbtw = max(root->evenbtw, l->evenbtw);
    root->evenbtw = max(root->evenbtw, r->evenbtw);
    return root;
}

void build(vector<node*> &segtree, int n) {
    // n = N
    int v;
    for (int i = n - 1; i > 0; i--) {
        segtree[i] = combine(segtree[2 * i], segtree[2 * i + 1]);
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

node *init(int v, int l) {
    node *root = new node();
    root->length = l;
    root->oddleft = l && !isEven(v) ? 1 : 0;
    root->oddright = l && !isEven(v) ? 1 : 0;
    root->oddbtw = l && !isEven(v) ? 1 : 0;
    root->evenleft = l && isEven(v) ? 1 : 0;
    root->evenright = l && isEven(v) ? 1 : 0;
    root->evenbtw = l && isEven(v) ? 1 : 0;
    return root;
}

void update(vector<node*> &segtree, int n, int p, int v) {
    p += n;
    segtree[p] = init(v, 1);
    p = p >> 1;
    while (p > 0) {
        segtree[p] = combine(segtree[2 * p], segtree[2 * p + 1]);
        p = p >> 1; 
    }
    return;
}

int largesteven(node *root) {
    return max(root->evenbtw, max(root->evenleft, root->evenright));
}

void print(vector<node*> &segtree) {
    for (int i = 1; i < segtree.size(); i++) {
        cout << segtree[i]->length << segtree[i]->oddleft << segtree[i]->oddright << segtree[i]->evenleft
        << segtree[i]->evenright << segtree[i]->oddbtw << segtree[i]->evenbtw << endl;
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
    vector<node*> segtree(2 * N);
    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        segtree[N + i] = init(v, 1);
    }
    // padding has no value
    for (int i = N + n; i < 2 * N; i++) {
        segtree[i] = init(0, 0);
    }
    build(segtree, N);
    // print(segtree);
    // process queries;
    cout << "Case #" << t << ": ";
    int p;
    for (int i = 0; i < q; i++) {
        cin >> p >> v;
        update(segtree, N, p, v);
        // print(segtree);
        // find largest interval
        cout << largesteven(segtree[1]) << " ";
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