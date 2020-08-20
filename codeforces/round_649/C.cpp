#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    vector<int> inf;
    int l = 0;
    for (int i = 0; i < n; i++) {
        inf.push_back(i);
        if (l > a[i]) {
            cout << -1 << endl;
            return;
        }
        if ((int) inf.size() < a[i] - l) {
            cout << -1 << endl;
            return;
        }
        while (l < a[i]) {
            b[inf.back()] = l;
            inf.pop_back();    
            l++;
        } 
    }
    for (auto i : inf) {
        b[i] = 1000000;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
