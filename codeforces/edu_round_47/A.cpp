#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int c[n], a[m];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> a[i];

    int p = 0, g = 0;
    for (int i = 0; i < n; i++) {
        if (p >= m) continue;
        if (a[p] >= c[i]) {
            g++;
            p++;
        }
    }
    cout << g << endl;
    return 0;
}