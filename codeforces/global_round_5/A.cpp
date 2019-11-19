#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int off = 1;
    for (int i = 0; i < n; i++) {
        if (abs(v[i]) % 2 == 0) {
            cout << v[i] / 2 << endl;
        }
        else if (v[i] > 0) {
            int x = v[i];
            x = (x + off) / 2;
            cout << x << endl;
            off *= -1;
        }
        else {
            int x = abs(v[i]);
            x = (x - off) / 2;
            cout <<  -1 * x << endl;
            off *= -1;
        }
    }
    return 0;
}