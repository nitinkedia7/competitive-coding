#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n), count(102);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        count[v[i]]++;
        if (v[i] % 2) odd++;
        else even++;
    }    
    if (odd % 2 == 0) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (count[v[i] + 1] > 0 || count[v[i] - 1] > 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
