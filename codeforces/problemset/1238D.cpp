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

ll find(string &s) {
    // AB+
    int n = s.length();
    vector<int> v(n);
    int ls = n;
    for (int i = n-1; i >= 0; i--) {
        v[i] = ls;
        if (s[i] == 'A') ls = i;
    }
    // print(v);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A' && (v[i] - i - 1) > 0) {
            ans += (v[i] - i - 1);
        }
    }
    return ans;
} 

void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll x1 = find(s);
    reverse(s.begin(), s.end());
    ll x2 = find(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') s[i] = 'B';
        else s[i] = 'A';
    }
    ll x3 = find(s);
    reverse(s.begin(), s.end());
    ll x4 = find(s);
    ll to = (n * 1LL * (n+1)) / 2;
    ll x = 0;
    for (int i = 0; i < n-1; i++) {
        if (s[i] != s[i+1]) x++;
    }
    // cout << to << " " << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x << endl; 
    cout << to - n - (x1 + x2 + x3 + x4) + x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}