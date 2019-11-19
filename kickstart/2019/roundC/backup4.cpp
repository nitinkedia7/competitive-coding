#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getKey(int r, int c, int n) {
    ll key = c;
    key += r * 1LL * n;
    return key;
}

struct Node {
    int n, s, e, w;
};

Node *create(int n, int s, int e, int w) {
    Node *root = new Node();
    root->n = n;
    root->s = s;
    root->e = e;
    root->w = w;
    return root;
}

void shift(int r, int c, int n, unordered_map<ll, Node*> &adj) {
    Node *base  = create(r - 1, r + 1, c + 1, c - 1);
    ll key = getKey(r-1, c, n);
    ll key2;
    if (adj.find(key) != adj.end()) {
        base->n = adj[key]->n;
        key2 = getKey(r + 1, c, n);
        if (adj.find(key2) != adj.end()) {
            adj[key]->s = adj[key2]->s;
        }
        else adj[key]->s = r + 1;
    }
    key = getKey(r + 1, c, n);
    if (adj.find(key) != adj.end()) {
        base->s = adj[key]->s;
        key2 = getKey(r - 1, c, n);
        if (adj.find(key2) != adj.end()) {
            adj[key]->n = adj[key2]->n;
        }
        else adj[key]->n = r - 1;
    }
    key = getKey(r, c + 1, n);
    if (adj.find(key) != adj.end()) {
        base->e = adj[key]->e;
        key2 = getKey(r, c - 1, n);
        if (adj.find(key2) != adj.end()) {
            adj[key]->w = adj[key2]->w;
        }
        else adj[key]->w = c - 1;
    }
    key = getKey(r, c - 1, n);
    if (adj.find(key) != adj.end()) {
        base->w = adj[key]->w;
        key2 = getKey(r, c + 1, n);
        if (adj.find(key2) != adj.end()) {
            adj[key]->e = adj[key2]->e;
        }
        else adj[key]->e = c + 1;
    }

    key = getKey(r, c, n);
    adj[key] = base;
}

void sherlock(int t) {
    int n, r, c, sr, sc;
    char dir;
    cin >> n >> r >> c >> sr >> sc;
    ll key;
    unordered_map<ll, Node*> adj;
    int N = 50001;
    shift(sr, sc, N, adj);
    for (int i = 0; i < n; i++) {
        cin >> dir;
        key = getKey(sr, sc, N);
        switch (dir) {
            case 'N':
                sr = adj[key]->n;
                break;
            case 'S':
                sr = adj[key]->s;
                break;
            case 'E':
                sc = adj[key]->e;
                break;
            case 'W':
                sc = adj[key]->w;
                break;
        }
        cout << sr << " " << sc << endl;
        shift(sr, sc, N, adj);
    }
    cout << "Case #" << t << ": " << sr << " " << sc << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}