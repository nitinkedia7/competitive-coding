#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int beauty(int n, string &s) {
    stack<int> s1, s2;
    s2.push(INT_MAX);
    int b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        c += (s[i] == ')' ? -1 : 1);
        s1.push(c);
        s2.push(min(s2.top(), c));
    }
    c = 0;
    int c1 = 0, c2, c3;
    for (int i = n-1; i >= 0; i--) {
        c3 = s1.top();
        c2 = s2.top();
        if (c-c1 >= 0 && c + c2 >= 0 && c + c3 == 0) {
            b++;
        }
        c += (s[i] == ')' ? -1 : 1);
        c1 = max(c, c1);
        s1.pop();
        s2.pop();
    }
    cout << s << " " << b << endl;
    return b;
}

void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l, r, mab = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(s[i], s[j]);
            int b = beauty(n, s);
            swap(s[i], s[j]);
            if (b > mab) {
                mab = b;
                l = i+1;
                r = j+1;
            }
        }
    }
    cout << mab << endl << l << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}