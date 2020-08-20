#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    if (n <= 3) {
        cout << s[0] << endl;
        return;
    }
    int l = 0, r = n - 1;
    string left, right;
    while (l <= r) {
        if (s[l] == s[r]) {
            left += s[l];
            if (l < r) right += s[r];
            r--;
        }
        else if (l <= r - 1 && s[l] == s[r-1]) {
            left += s[l];
            if (l < r - 1) right += s[r-1];
            r -= 2;
        }
        l++;
    }
    int p = left.size() + right.size();
    if (p < n / 2) {
        cout << "IMPOSSIBLE" << endl;
    }    
    else {
        reverse(all(right));
        cout << left << right << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
