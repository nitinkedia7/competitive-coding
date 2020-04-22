#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool xg = false;
    string a;
    string b;
    for (int i = 0; i < s.length(); i++) {
        a.push_back(s[i]);
        b.push_back(s[i]);
        if (!xg) {
            if (s[i] == '0') {
                a[i] = '0';
                b[i] = '0';
            }
            else if (s[i] == '2') {
                a[i] = '1';
                b[i] = '1';
            }
            else if (s[i] == '1') {
                a[i] = '1';
                b[i] = '0';
                xg = true;
            }
        }
        else {
            if (s[i] == '0') {
                a[i] = '0';
                b[i] = '0';
            }
            else if (s[i] == '2') {
                a[i] = '0';
                b[i] = '2';
            }
            else if (s[i] == '1') {
                a[i] = '0';
                b[i] = '1';
            }
        }
    }
    cout << a << endl;
    cout << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}