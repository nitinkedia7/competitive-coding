#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int r, b, c;
    cin >> r >> b >> c;
    if (r > 5 || b > 20 || c > 5) exit(0);
    vector<int> ma(5), s(5), p(5);
    for (int i = 0; i < c; i++) {
        cin >> ma[i] >> s[i] >> p[i];
    }
    // print(ma);
    // print(s);
    // print(p);

    ll mint = LLONG_MAX;
    for (int i = 0; i <= b; i++) {
        for (int j = 0; j <= (b-i); j++) {
            for (int k = 0; k <= (b-i-j); k++) {
                for (int l = 0; l <= (b-i-j-k); l++) {
                    int m = b - i - j - k - l;
                    if (c < 5 && m != 0) continue;
                    if (c < 4 && l != 0) continue;
                    if (c < 3 && k != 0) continue;
                    if (c < 2 && j != 0) continue;  
                    if (i + j + k + l + m != b) continue;
                    int z = 0;
                    if (i != 0) z++;
                    if (j != 0) z++;
                    if (k != 0) z++;
                    if (l != 0) z++;
                    if (m != 0) z++;
                    if (z > r) continue;

                    if (i > ma[0] || j > ma[1] || k > ma[2] || l > ma[3] || m > ma[4]) continue;
                    // cout << "hi" << endl;
                    ll t = LLONG_MIN;
                    if (i > 0 && i <= ma[0]) {
                        t = max(t, p[0] + i * 1LL * s[0]);
                    }
                    if (j > 0 && j <= ma[1]) {
                        t = max(t, p[1] + j * 1LL * s[1]);
                    }
                    if (k > 0 && k <= ma[2]) {
                        t = max(t, p[2] + k * 1LL * s[2]);
                    }
                    if (l > 0 && l <= ma[3]) {
                        t = max(t, p[3] + l * 1LL * s[3]);
                    }
                    if (m > 0 && m <= ma[4]) {
                        t = max(t, p[4] + m * 1LL * s[4]);
                    }
                    if (t != LLONG_MIN && t < mint) {
                        // cout << i << " " << j << " " << k << " " << l << " " << m << endl;
                        mint = min(t, mint);
                    }
                }
            }
        } 
    }
    ma.clear();
    s.clear();
    p.clear();
    cout << "Case #" << t << ": " << mint << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}