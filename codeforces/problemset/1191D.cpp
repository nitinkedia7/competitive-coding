#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }
    int c2 = 0, c3 = 0, z;
    for (auto x : m) {
        if (x.second == 2) {
            c2++;
            z = x.first;
        }
        else if (x.second > 2) c3++;
    }
    if (c3 > 0 || c2 > 1) {
        cout << "cslnb" << endl;
        return;
    }
    if (c2 == 1 && (z == 0 || m.find(z-1) != m.end())) {
        cout << "cslnb" << endl;
        return;
    }
    string f = "sjfnb", s = "cslnb";
    if (c2 == 1) {
        m[z]--;
        m[z-1]++;
        swap(f, s);
    }   
    ll p = 0; 
    int i = 0; 
    for (auto x : m) {
        p += (x.first - i);
        i++;
    }
    if (p % 2 == 1) {
        cout << f << endl;
    }
    else {
        cout << s << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}