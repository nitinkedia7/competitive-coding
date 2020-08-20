#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void p_2(int t, int n, int p, vector<int> &v) {
    if (p != 2) return;
    int x0 = 0, x1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) x0++;
        else x1++;
    }
    cout << "Case #" << t << ": " << x0 + (x1 + 1) / 2 << endl;
}

void p_3(int t, int n, int p, vector<int> &v) {
    if (p != 3) return;
    int x0 = 0, x1 = 0, x2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 3 == 0) x0++;
        else if (v[i] % 3 == 1) x1++;
        else x2++;
    }
    if (x1 > x2) swap(x1, x2);
    cout << "Case #" << t << ": " << x0 + x1 + (x2 - x1 + 2) / 3 << endl;
}

void p_4(int t, int n, int p, vector<int> &v) {
    if (p != 4) return;
    int x0 = 0, x1 = 0, x2 = 0, x3 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 4 == 0) x0++;
        else if (v[i] % 4 == 1) x1++;
        else if (v[i] % 4 == 2) x2++;
        else x3++;
    }
    int ans = x0;
    ans += x2 / 2;
    x2 = x2 % 2;
    if (x2 == 0) { // no two's
        if (x1 > x3) swap(x1, x3);
        ans += x1 + (x3 - x1 + p - 1) / p;
    }
    else {
        if (x1 > x3) swap(x1, x3);
        ans += x1;
        x3 -= x1;
        if (x3 <= 2) {
            ans++;
        } 
        else {
            ans++;
            x3 -= 2;
            ans += (x3 + p - 1) / p;
        }
    }
    cout << "Case #" << t << ": " << ans << endl;
}


void sherlock(int t) {
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    p_2(t, n, p, v);
    p_3(t, n, p, v);
    p_4(t, n, p, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
