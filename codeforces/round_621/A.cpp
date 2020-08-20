#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    bool possible = true;
    int i = 1;
    while (possible) {
        possible = false;
        if (i >= n) continue;
        if (v[i] == 0) {
            possible = true;
            i++;
        }
        else if (d >= i) {
            possible = true;
            d -= i;
            v[0]++;
            v[i]--;
        }
    }
    cout << v[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
