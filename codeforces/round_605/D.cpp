#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> endat(n, 1), startat(n, 1);
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i-1]) endat[i] = 1 + endat[i-1];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i+1]) startat[i] = 1 + startat[i+1];
    }
    // print(endat);
    // print(startat);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, endat[i] + startat[i] - 1);
        if (i > 0 && i < n - 1 && v[i-1] < v[i+1]) {
            ans = max(ans, endat[i-1] + startat[i+1]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(1);
    return 0;
}