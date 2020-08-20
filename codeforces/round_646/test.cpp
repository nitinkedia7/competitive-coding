#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, x;
    cin >> n >> x;
    int l = 0, r = n-1;
    int c = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i ++) {
        v[i] = rand() % n;
    } 
    x = *max_element(all(v));
    // iota(all(v), 0);
    // random_shuffle(all(v));
    while (l <= r) {
        int mid = (l + r) / 2;
        int y = *max_element(v.begin() + l, v.begin() + mid + 1);
        if (y < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
        c++;
    }
    cout << c << " " << l << " " << v[l] << endl;
}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
