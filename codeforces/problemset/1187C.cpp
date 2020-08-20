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

void print(vector<pair<int,int>> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i].first << "," << v[i].second << " ";
    }
    cout << endl;
}

bool is_sorted(vector<pair<int,int>> &is, pair<int,int> p) {
    for (int i = 0; i < (int) is.size(); i++) {
        if (is[i].first <= p.first && p.second <= is[i].second) {
            return true;
        }
    }
    return false;
}

void sherlock(int tc) {
    int n, m;
    cin >> n >> m;
    vector<int> s(n, - 1);
    vector<pair<int,int>> ns, is;
    int t, l, r;
    for (int i = 0; i < m; i++) {
        cin >> t >> l >> r;
        l--;
        r--;
        if (t) {
            s[l] = max(s[l], r);
        }
        else {
            ns.push_back({l, r});
        }
    }
    int i = 0;
    while (i < n) {
        if (s[i] == -1) {
            i++;
            continue;
        }
        int j = i + 1, r = s[i];
        while (j < n && j <= r) {
            r = max(r, s[j]);
            j++;
        }
        is.push_back({i, j - 1});
        i = j;
    }
    // print(is);
    // print(ns);
    for (int i = 0; i < (int) ns.size(); i++) {
        if (is_sorted(is, ns[i])) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<int> v(n);
    v[0] = 1;
    for (int i = 1; i < n; i++) {
        if (is_sorted(is, {i-1, i})) {
            v[i] = v[i-1] + 1;
        }
        else {
            v[i] = v[i-1] - 1;
        }
    }
    int x = *min_element(all(v));
    if (x <= 0) {
        for (int i = 0; i < n; i++) {
            v[i] += (1 - x);
        }
    }
    cout << "YES" << endl;
    print(v); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
