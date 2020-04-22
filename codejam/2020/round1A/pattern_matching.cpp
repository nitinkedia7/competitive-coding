#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<string> l(50), m(50), r(50);

bool is_prefix(string &a, string &b) {
    if (a.length() > b.length()) return false;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool is_suffix(string &a, string &b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool ans = is_prefix(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    return ans;
}

void sherlock(int t) {
    int n;
    cin >> n;
    string p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        int j = 0;
        while (p[j] != '*') j++;
        l[i] = p.substr(0, j);
        int k = p.length() - 1;
        while (p[k] != '*') k--;
        r[i] = p.substr(k+1, p.length() - k - 1);
        m[i] = p.substr(j, k-j);
        p.clear();
    }
    // check prefix
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (l[i].length() > l[x].length()) x = i;
    }   
    bool b = true;
    for (int i = 0; i < n; i++) {
        b = b && is_prefix(l[i], l[x]);
    }
    if (!b) {
        cout << "Case #" << t << ": *" << endl;
        return;     
    }

    // check suffix
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (r[i].length() > r[y].length()) y = i;
    }
    b = true;
    for (int i = 0; i < n; i++) {
        b = b && is_suffix(r[i], r[y]);
    }
    if (!b) {
        cout << "Case #" << t << ": *" << endl;
        return;     
    }
    string ans;
    ans += l[x];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i].length(); j++) {
            if (m[i][j] != '*') ans += m[i][j];
        }
    } 
    ans += r[y];
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}