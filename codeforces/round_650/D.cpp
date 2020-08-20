#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int tc) {
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for (int i = 0; i < (int) s.length(); i++) {
        count[s[i] - 'a']++;
    }
    int m;
    cin >> m;
    vector<int> b(m), done(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int rem = m, max_letter = 25;
    vector<int> zeroes;
    vector<char> t(m, '#');
    while (rem > 0) {
        zeroes.clear();
        for (int i = 0; i < m; i++) {
            if (!done[i] && b[i] == 0) {
                zeroes.push_back(i);
                done[i] = 1;
            }
        }
        assert((int) zeroes.size() > 0);
        while (count[max_letter] < (int) zeroes.size()) {
            max_letter--;
        }
        assert(max_letter >= 0);
        for (auto i : zeroes) {
            t[i] = 'a' + max_letter;
        }
        for (int i = 0; i < m; i++) {
            if (done[i]) continue;
            for (auto j : zeroes) {
                b[i] -= abs(j - i);
            }
        }
        rem -= zeroes.size();
        max_letter--;
    }
    for (int i = 0; i < (int) t.size(); i++) {
        cout << t[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
