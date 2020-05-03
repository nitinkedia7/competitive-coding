#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N = 10000;

void sherlock(int t) {
    int u;
    cin >> u;
    ll m;
    string s, ms;
    vector<int> pres(26), pres_msb(26), ub(26, 9), pres_m(26);
    vector<pair<ll,string>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> m >> s;
        m = -1;
        v[i] = {m, s};
        pres_msb[s[0] - 'A'] = 1;
        pres_m[s[0] - 'A']++;
        for (int j = 0; j < (int) s.length(); j++) {
            pres[s[j] - 'A']++;
        }
        if (m == -1) continue;
        ms = to_string(m);
        if (s.length() == ms.length()) {
            int x = s[0] - 'A';
            ub[x] = min(ub[x], ms[0] - '0');
        }
    }
    // find zero
    int z = -1;
    for (int i = 0; i < 26; i++) {
        if (pres_msb[i] == 0 && pres[i] > 0) {
            z = i;
            break;
        }
    }
    vector<tuple<int,int,int>> x;
    for (int i = 0; i < 26; i++) {
        if (pres[i] > 0 && i != z) {
            x.push_back({ub[i], -1 * pres_m[i], i});
        }
    }
    assert(x.size() >= 9);
    sort(all(x));
    string D;
    D.push_back((char) ('A' + z));
    for (int i = 0; i < 9; i++) {
        int y = get<2> (x[i]);
        D.push_back((char) ('A' + y));
    }
    cout << "Case #" << t << ": " << D << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
