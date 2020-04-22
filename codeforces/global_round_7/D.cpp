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

void calc1(string &s, int n, vector<int> &d1) {
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
}

void calc2(string &s, int n, vector<int> &d2) {
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
}

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> d1(n), d2(n);
    calc1(s, n, d1);
    calc2(s, n, d2);

    int ans = 0;
    int z = -1, d;
    for (int i = 0; i < n; i++) {
        int l = i - d1[i] + 1;
        int r = i + d1[i] - 1;
        if (l == 0 || r == n-1) {
            if (r - l + 1 > ans) {
                z = i;
                ans = r - l + 1;
            } 
        }
    }
    string s1 = s.substr(z - d1[z] + 1, 2 * d1[z] - 1);

    z = -1;
    for (int i = 0; i < n; i++) {
        if (d2[i] == 0) continue;
        int l = i - d2[i];
        int r = i + d2[i] - 1;
        if (l == 0 || r == n-1) {
            if (r - l + 1 > ans) {
                z = i;
                ans = r - l + 1;
            } 
        }
    }
    string s2;
    if (z != -1) {
        s2 = s.substr(z - d2[z], 2 * d2[z]);
    }

    int l = 0, r = n-1;
    while (l < r && s[l] == s[r]) { 
        l++;
        r--;
    }
    ans = max(ans, 2 * l);
    string s3 = s.substr(0, l) + s.substr(r+1, l);
    
    z = -1;
    for (int i = l; i <= r; i++) {
        int x = min(i - l + 1, r - i + 1);
        if (d1[i] >= x) {
            int len = 2 * l + 2 * x - 1;
            if (len >= ans) {
                ans = len;
                z = i;
                d = x;
            }
        }
    }
    string s4;
    if (z != -1) {
        s4 = s.substr(0, l) + s.substr(z-d+1, 2 * d - 1) + s.substr(r+1, l);
    }
    
    z = -1;
    for (int i = l+1; i <= r; i++) {
        if (s[i] != s[i-1]) continue;
        int x = min(i - l, r - i + 1);
        if (d2[i] >= x) {
            int len = 2 * l + 2 * x;
            if (len >= ans) {
                ans = len;
                z = i;
                d = x;
            }
        }
    }
    string s5;
    if (z != -1) {
        s5 = s.substr(0, l) + s.substr(z - d, 2 * d) + s.substr(r+1, l);
    }
    string as;
    if (s1.length() > as.length()) {
        as = s1;
    }
    if (s2.length() > as.length()) {
        as = s2;
    }
    if (s3.length() > as.length()) {
        as = s3;
    }
    if (s4.length() > as.length()) {
        as = s4;
    }
    if (s5.length() > as.length()) {
        as = s5;
    }
    cout << as << endl;
    // cout << ans << endl;
    // assert((int) as.length() == ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}