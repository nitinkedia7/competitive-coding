#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;


void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') c0++;
        if (s[i] == '1') c1++;
    }
    if (c1 == 0 || c0 == 0) {
        cout << s << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << "01";
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