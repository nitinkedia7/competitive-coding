#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N = 100000;

vector<int> v(N);

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    int k_c = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == k) k_c++;
    }
    if (k_c == 0) {
        cout << "no" << endl;
        return;
    }
    if (n == 1) {
        cout << "yes" << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] >= k && v[i+1] >= k) {
            cout << "yes" << endl;
            return;
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if (v[i] >= k && v[i+1] < k && v[i+2] >= k) {
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
