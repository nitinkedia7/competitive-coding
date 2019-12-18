#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int encode(string &s) {
    return 2 * (s[0] - '0') + (s[s.length() - 1] - '0');
}

void sherlock(int x) {
    int n;
    cin >> n;
    string t, r, s[n];
    int zz = 0, zo = 0, oz = 0, oo = 0;
    unordered_set<string> seen, bad;
    for (int i = 0; i < n; i++) {
        cin >> t;
        s[i] = t;
        switch (encode(t)) {
            case 0:
                zz++;
                break;
            case 1:
                zo++;
                r = string(t.rbegin(), t.rend());
                if (seen.find(r) != seen.end()) {
                    bad.insert(t);
                    bad.insert(r);
                }
                seen.insert(t);
                break;
            case 2:
                oz++;
                r = string(t.rbegin(), t.rend());
                if (seen.find(r) != seen.end()) {
                    bad.insert(t);
                    bad.insert(r);
                }
                seen.insert(t);
            case 3:
                oo++;
                break;
            default:
                assert(false);
        }
    }
    if (oz == 0 && zo == 0) {
        if (zz == 0 || oo == 0) {
            cout << 0 << endl << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    else {
        int ans = abs(oz - zo) / 2;
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            if (ans == 0) break;
            int e = encode(s[i]);
            if (oz > zo && e == 2 && bad.find(s[i]) == bad.end()) {
                cout << i + 1 << " ";
                ans--;
            }
            if (zo > oz && e == 1 && bad.find(s[i]) == bad.end()) {
                cout << i + 1 << " ";
                ans--;
            }
        }
        cout << endl;
    }
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