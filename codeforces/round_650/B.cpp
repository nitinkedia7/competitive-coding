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
    int odd_bad = 0, even_bad = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && v[i] % 2 != 0) {
            even_bad++;
        }
        if (i % 2 == 1 && v[i] % 2 == 0) {
            odd_bad++;
        }
    }
    if (odd_bad == even_bad) {
        cout << odd_bad << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
