#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, x;
    cin >> n >> x;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2) a++;
        else b++;
    }    
    int odd_count = 1;
    while (odd_count <= a && odd_count <= x) {
        if (b >= x - odd_count) {
            cout << "Yes" << endl;
            return;
        }
        odd_count += 2;
    }
    cout << "No" << endl;
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
