#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void monocarp(pair<int,int> &l, pair<int,int> &r) {
    int maxl = l.first + (l.second + 1) / 2;
    int maxr = r.first + (r.second + 1) / 2;
    if (maxl > maxr) {
        if (l.second > 0) {
            l.first += 9;
            l.second--;
        }
        else {
            if (maxl - r.first < 9) {
                r.first += 9;
            } 
            r.second--;
        }
    }
    else {
        if (r.second > 0) {
            r.first += 9;
            r.second--;
        }
        else {
            if (maxr - l.first < 9) {
                l.first += 9;
            } 
            l.second--;
        }
    }
}

void bicarp(pair<int,int> &l, pair<int,int> &r) {
    int maxl = l.first + (l.second) / 2;
    int maxr = r.first + (r.second) / 2;
    if (maxl >= maxr) {
       if (l.second > 0) {
           l.second--;
       }
       else {
           r.first += min(9, maxl - r.first);
           r.second--;
       }
    }
    else {
        if (r.second > 0) {
           r.second--;
        }
        else {
            l.first += min(9, maxr - l.first);
            l.second--;
        }
    }
}

void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int,int> l{0, 0}, r{0, 0};
    int q = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?') {
            l.second++;
            q++;
        }
        else {
            l.first += (s[i] - '0');
        }
    }
    for (int i = n/ 2; i < n; i++) {
        if (s[i] == '?') {
            r.second++;
            q++;
        }
        else {
            r.first += (s[i] - '0');
        }
    }
    for (int i = 0; i < q / 2; i++) {
        monocarp(l, r);
        bicarp(l, r);
    }
    cout << (l.first == r.first ? "Bicarp" : "Monocarp") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
