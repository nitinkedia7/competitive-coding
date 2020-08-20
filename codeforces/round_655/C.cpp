#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int process(vector<int> &v, int x, int y) {
    // cout << x << " " << y << endl;
    int k = 0;
    for (int i = x; i <= y; i++) {
        if (v[i] == i) k++;
    }
    if (k == y - x + 1) return 0;
    else if (k == 0) return 1;
    else return 2; 
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }    
    int i = 0, ans = 0;
    while (i < n) {
        int j = i, r = v[i];
        while (j <= r) {
            r = max(r, v[j]);
            j++;
        }
        ans = max(ans, process(v, i, j - 1));
        i = j;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
