#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int k = 127; k >= 0; k--) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (v[i] ^ k);
        }
        if (sum <= m) {
            cout << "Case #" << t << ": " << k << endl;
            return;
        }
    }
    cout << "Case #" << t << ": " << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}