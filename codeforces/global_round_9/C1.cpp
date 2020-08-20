#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    vector<int> max_till_now(n), min_till_now(n), min_r(n);
    max_till_now[0] = v[0];
    min_till_now[0] = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max_till_now[i-1]) {
            max_till_now[i] = v[i];
        }
        else max_till_now[i] = max_till_now[i-1];
        if (v[i] < min_till_now[i-1]) {
            min_till_now[i] = v[i];
        }
        else min_till_now[i] = min_till_now[i-1];
    }
    min_r[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (v[i] < min_r[i+1]) min_r[i] = v[i];
        else min_r[i] = min_r[i+1];
    }
    for (int i = 0; i < n; i++) {
        bool x = max_till_now[i] == v[i];
        bool y = true;
        if (i < n - 1) {
            y = min_till_now[i] < min_r[i+1];
        } 
        if (x && y) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
