#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool find_gap_sequence(int max_value, int k, vector<int> &v) {
    int n = v.size();
    int f = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] <= max_value) {
            f++;
            i++;
        }
    }
    return f >= k;
}

int bs(int k, int n, vector<int> &v) {
    int l = *min_element(all(v)), r = *max_element(all(v));
    while (l <= r) {
        int mid = (l + r) / 2;
        if (!find_gap_sequence(mid, k, v)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (k % 2 == 1) {
        v.push_back(INT_MIN);
        k++;
        n++;
    }
    int odd = bs(k / 2, n, v);
    reverse(all(v));
    int even = bs(k / 2, n, v);    
    cout << min(odd, even) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
