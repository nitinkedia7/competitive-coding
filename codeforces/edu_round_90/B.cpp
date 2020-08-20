#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int z = 0;
    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] == '0') z++;
    }    
    z = min(z, (int) s.length() - z);
    cout << (z % 2 ? "DA" : "NET") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
