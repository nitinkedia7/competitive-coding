#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;


void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int hn = n / 2;
    string ans;
    for (int i = 0; i < k-1; i++) {
        ans.push_back('(');
        ans.push_back(')');
    }
    for (int i = 0; i < hn-k+1; i++) {
        ans.push_back('(');
    }
    for (int i = 0; i < hn-k+1; i++) {
        ans.push_back(')');
    }
    assert(s.length() == ans.length());
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        if (s[i] == ans[i]) {
            cout << i+1 << " " << i+1 << endl;
            continue;
        }
        int j = i+1;
        while (s[j] == s[i]) j++;
        cout << i+1 << " " << j+1 << endl;
        reverse(s.begin() + i, s.begin() + j + 1);
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