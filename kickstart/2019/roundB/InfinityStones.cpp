#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct stone {
    int s;
    int e;
    int l;
};

stone *create() {
    stone *gamma = new stone();
    cin >> gamma->s >> gamma->e  >> gamma->l;
    return gamma; 
}

bool comp(stone* x, stone* y) {
    return x->s * y->l < y->s * x->l;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<stone *> ig(n);
    int tt = 0;
    for (int i = 0; i < n; i++) {
        ig[i] = create();
        tt += ig[i]->s;
    } 
    sort(ig.begin(), ig.end(), comp);
    // for (int i = 0; i < n; i++) {
    //     cout << ig[i]->s << " " << ig[i]->e << " ";
    // }
    // cout << endl;
    // knapsack
    vector<vector<int>> opt(n + 1, vector<int> (tt + 1));
    for (int j = 0; j <= tt; j++) {
        opt[n][j] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= tt; j++) {
            if (j + ig[i]->s <= tt) opt[i][j] = opt[i+1][j + ig[i]->s];
            opt[i][j] += max(0, ig[i]->e - j * ig[i]->l);
            if (opt[i+1][j] > opt[i][j]) {
                opt[i][j] = opt[i+1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= tt; j++) {
    //         cout << opt[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "Case #" << t << ": " << opt[0][0] << endl;
    opt.clear();
    ig.clear();
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}