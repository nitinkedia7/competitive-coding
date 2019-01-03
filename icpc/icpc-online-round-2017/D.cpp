#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t, n, m, d, D;
    cin >> t;
    for (; t > 0; t--) {
        cin >> n >> m >> d >> D;
        if (m < n*d || m > n*D) {
            cout << "-1" << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < i+d; j++) {
                    cout << i+1 << " " << j%n + 1 << endl;
                }
            }
            int o = d, c = m-n*d;
            for (int i = 0; i < n-d; i++) {
                for (int j = 0; j < n; j++) {
                    if (c <= 0) break;
                    cout << j+1 << " " << (j+o)%n+1 << endl;
                    c--;
                }
                o++;
            }
        }
    }
}