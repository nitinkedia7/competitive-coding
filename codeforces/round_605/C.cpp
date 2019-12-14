#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    string s;
    char a;
    cin >> s;
    vector<int> ava(26);
    for (int i = 0; i < k; i++) {
        cin >> a;
        ava[a - 'a'] = 1;
    }
    int j = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (j < i) j = i;
        while (j < n && ava[s[j] - 'a']) j++;
        ans += (j - i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}