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
    bool b = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == k) b = true; 
    }
    if (!b) {
        cout << "no" << endl;
        return;
    }
    if (n == 1) {
        cout << "yes" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] != k) continue;
        if (i > 0 && v[i-1] >= k) {
            cout << "yes" << endl;
            return;
        }
        if (i < n-1 && v[i+1] >= k) {
            cout << "yes" << endl;
            return;
        }
    }
    vector<int> x(n);
    iota(all(x), 0);
    random_shuffle(all(x));
    for (int i = 0; i < n; i++) {
        int s = x[i];
        int l = (n - s);
        int sm = 0, eq = 0, gr = 0;
        for (int j = s; j < n; j++) {
            if (v[j] > k) gr++;
            else if (v[j] == k) eq++;
            else sm++;
            int p = (j - s + 1 + 1) / 2;
            if ((j-s+1) > 1 && eq > 0 && p > sm && p <= sm + eq) {
                // cout << s << " " << j << endl;
                cout << "yes" << endl;
                return;
            }   
            if (sm >= (l + 1) / 2  || gr >= (l + 1) / 2) {
                break;
            }         
        }
    }
    cout << "no" << endl;
}

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
