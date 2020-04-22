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
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = max(a[i], b[i-1]);
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        int d = b[i] - a[i], y = -1;
        for (int j = 0; j < 31; j++) {
            if (d & (1 << j)) {
                y = j;
            }
        }
        x = max(x, y+1);
    }
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}