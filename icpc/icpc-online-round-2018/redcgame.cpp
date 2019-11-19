#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    int n, k;
    for (;t > 0; t--) {
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (v[i] <= k) continue;
            else if (i+1 < n) {
                int d = v[i] - k;
                v[i] = k;
                v[i+1] -= d;
            }
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
        }
        cout << sum << endl;
    }
}