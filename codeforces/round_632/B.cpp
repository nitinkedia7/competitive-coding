#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int p = n, m = n;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == -1) m = i;
        if (a[i] == 1) p = i;
    }
    for (int i = n-1; i>= 0; i--) {
        if (b[i] > a[i] && p >= i) {
            cout << "NO" << endl;
            return;
        }
        if (b[i] < a[i] && m >= i) {
            cout << "NO" << endl;
            return;
        } 
    }   
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}