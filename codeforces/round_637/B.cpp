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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), peak(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int np = 0;
    for (int i = 1; i < k-1; i++) {
        if (v[i] > v[i-1] && v[i] > v[i+1]) {
            peak[i] = 1;
            np++;
        }
    }
    // cout << np << " " << 0 << endl;
    int mp = np, l = 0;
    for (int i = k-1; i < n-1; i++) {
        if (peak[i-k+2] == 1) {
            np--;
        }
        if (v[i] > v[i-1] && v[i] > v[i+1]) {
            peak[i]++;
            np++;
        }
        if (np > mp) {
            mp = np;
            l = i-k+2;
        }
        // cout << np << " " << i-k+2 << endl;
    }
    // print(peak);
    cout << mp+1 << " " << l+1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}