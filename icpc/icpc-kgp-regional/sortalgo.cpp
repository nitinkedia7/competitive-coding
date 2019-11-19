#include <bits/stdc++.h>
using namespace std;

int bcount(vector<int> &v, int l, int r, int s) {
    int li = max(0, s);
    if (l < -1 || r > v.size() || li >= v.size()) return 0;
    int c = 0;
    for (int i = l+1; i < r; i++) { // (l, r)
        if (v[i] >= v[li]) {
            li = i;
            c++;
        }
    }
    return c;
}

int main() {
    int t, n, d;
    vector<int> v;
    cin >> t;
    for (; t > 0; t--) {
        cin >> n;
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> d;
            v.push_back(d);
        }
        vector<int> ib;
        int li = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= v[li]) {
                li = i;
                ib.push_back(i);
            }
        }
        int c = ib.size();
        // cout << "b_size = " << c << endl;
        vector<int> opt(n, c);
        for (int i = 0; i < c; i++) {
            int j = ib[i];
            opt[j] -= 1;
            int l = j;
            int r;
            if (i < c-1) r = ib[i+1];
            else r = n;
            if (j == 0) opt[j] += bcount(v, l, r, 1);
            else opt[j] += bcount(v, l, r, ib[i-1]);
        }
        int m = 0;
        for (int i = 0; i < n; i++) m = max(m, opt[i]);
        cout << max(m, c) << endl;
    }
}