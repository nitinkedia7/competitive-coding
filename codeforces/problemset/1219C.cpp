#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int comp(string &a, int s, int l) {
    for (int i = 0; i < l; i++) {
        if (a[s + i] > a[i]) {
            // cout << a[s+i] << "," << a[i] << endl;
            return 2;
        }
        else if (a[s+i] < a[i]) {
            // cout << a[s+i] << ":" << a[i] << endl;
            return 0;
        }
    }
    return 1;
} 

void sherlock(int tt) {
    int l;
    cin >> l;
    string a;
    cin >> a;
    int n = a.size();
    string t(n+1, '0');
    int c = 1;
    for (int i = n-1; i >= 0; i--) {
        int x = a[i] - '0';
        x += c;
        c = x / 10;
        x %= 10;
        t[i+1] = '0' + x;
    }
    t[0] += c;
    if (t[0] == '0') {
        a = t.substr(1, n);
    }
    else {
        a = t;
        n++;
    }
    // cout << a << endl;

    if (n % l != 0) {
        n = l * ((n + l - 1) / l);
        a.resize(n);
        a[0] = '1';
        fill(a.begin() + 1, a.end(), '0');
    }
    int s = n / l;
    for (int i = 1; i < s; i++) {
        int b = comp(a, i * l, l);
        // cout << i * l << " " << b << endl;
        if (b == 2) {
            int c = 1;
            for (int i = l-1; i >= 0; i--) {
                int x = a[i] - '0';
                x += c;
                c = x / 10;
                x %= 10;
                a[i] = '0' + x;
            }
            break;
        }
        else if (b == 0) {
            break;
        }
    }
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < l; j++) {
            cout << a[j];
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
