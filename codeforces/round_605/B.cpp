#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock() {
    string s;
    cin >> s;
    int n = s.length();
    int l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'L':
                l++;
                break;
            case 'R':
                r++;
                break;
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            default:
                assert(false);
        }
    }
    int x = min(u, d), y = min(l, r);
    if (x == 0 && y == 0) {
        cout << 0 << endl;
    }
    else if (x == 0 && y != 0) {
        cout << 2 << endl;
        cout << "LR" << endl;
    } 
    else if (x != 0 && y == 0) {
        cout << 2 << endl;
        cout << "UD" << endl;
    }
    else {
        cout << 2 * (min(u, d) + min(l, r)) << endl;
        for (int i = 0; i < min(u, d); i++) cout << 'U';
        for (int i = 0; i < min(l, r); i++) cout << 'L';
        for (int i = 0; i < min(u, d); i++) cout << 'D';
        for (int i = 0; i < min(l, r); i++) cout << 'R';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock();
    return 0;
}