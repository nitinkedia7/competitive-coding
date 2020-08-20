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

void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    int c = 0, op = 0;
    for (int i = 0; i < n; i++) {
        c += (s[i] == '(' ? 1 : -1);
        if (s[i] == '(') op++;
        v[i] = c;
    }
    if (op != n-op) {
        cout << 0 << endl << 1 << " " << 1 << endl;
        return;
    }
    int mi = min_element(v.begin(), v.end()) - v.begin();
    string s1;
    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
        v1[i] = v[(i+mi) % n];
        v1[i] -= v[mi];
        s1.push_back(s[(i+mi) % n]);
    }
    // v1 is in canonical form
    v = v1;
    s = s1;
    // cout << endl << s << endl;
    // print(v);
    int base = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) base++;
    }
    int mab = base, x = 0, y = 0;
    // cout << mab << endl << x+1 << " " << y+1 << endl;
    vector<int> pos = {-1};
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) pos.push_back(i);
    }
    pos.push_back(n);
    for (int i = 0; i < pos.size()-1; i++) {
        int l = pos[i]+1, r = pos[i+1];
        while (l < r && s[l] == ')') l++;
        while (l < r && (s[r % n] == '(')) r--;
        if (l >= r) continue;
        int c1 = 0;
        for (int j = l; j < r; j++) {
            if (v[j] == 1) c1++;
        }
        if (c1 > mab) {
            mab = c1;
            x = l;
            y = r % n;
        }
    }
    // cout << mab << endl << x+1 << " " << y+1 << endl;
    pos.clear();
    pos.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) pos.push_back(i);
        else if (v[i] == 1) pos.push_back(i);
    }
    pos.push_back(n);
    for (int i = 0; i < pos.size()-1; i++) {
        int l = pos[i]+1, r = pos[i+1];
        while (l < r && s[l] == ')') l++;
        while (l < r && s[r % n] == '(') r--;
        if (l >= r) continue;
        int c2 = 0;
        for (int j = l; j < r; j++) {
            if (v[j] == 2) c2++;
        }
        if (c2 + base > mab) {
            mab = c2 + base;
            x = l;
            y = r % n;
        }
    }
    cout << mab << endl << (x+mi) % n + 1 << " " << (y + mi) % n + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}