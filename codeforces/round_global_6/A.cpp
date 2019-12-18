#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int z = 0, sum = 0, e = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') z++;
        if ((s[i] - '0') % 2 == 0) e++;
        sum += (s[i] - '0');
    }
    if (sum % 3 == 0 && e > 1 && z > 0) {
        cout << "red" << endl;
    }
    else cout << "cyan" << endl;
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