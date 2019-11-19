#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rsum(vector<int> &prefix, int i, int j, int n) {
    // [i, j]
    return prefix[n - 1] - (prefix[j] - (i > 0 ? prefix[i-1] : 0));
}

void print(vector<vector<ll>> &opt, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << opt[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> eat(n), energy(n), decay(n);
    for (int i = 0; i < n; i++) {
        cin >> eat[i] >> energy[i] >> decay[i];
    } 
    vector<vector<ll>> opt(n, vector<ll> (n));
    vector<int> prefix(n);
    prefix[0] = eat[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + eat[i];
    }
    int tt = prefix[n - 1];
    ll re;
    for (int i = 0; i < n; i++) {
        re = energy[i] - decay[i] * 1LL * (tt - eat[i]); 
        opt[i][i] = max(0LL, re);
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // select last;
            int et = rsum(prefix, i, j, n);
            ll dose = LLONG_MIN;
            for (int k = i; k <= j; k++) {
                ll e = energy[k] - decay[k] * 1LL * et;
                if (e < 0) e = 0;
                if (k > i) {
                    e += opt[i][k-1];
                }
                if (k < j) {
                    e += opt[k+1][j];
                }
                dose = max(dose, e);
            }
            opt[i][j] = dose;
        }
    } 
    cout << "Case #" << t << ": " << opt[0][n-1] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}