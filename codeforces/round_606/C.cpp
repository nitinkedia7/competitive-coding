#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ir(n);
    int c = 0;
    for (int i = 0; i < n - 2; i++) {
        if (ir[i]) continue;
        if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
            if (i > 0 && ir[i-1] == 0 && s[i-1] == 'o') {
                ir[i+1] = 1;
            }
            else ir[i] = 1;
            c++;
        }
        if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
            if (i + 3 < n && ir[i+3] == 0 && s[i+3] == 'o') {
                ir[i+1] = 1;
            }
            else ir[i+2] = 1;
            c++;
        }
    }
    cout << c << endl;
    for (int i = 0; i < n; i++) {
        if (ir[i]) cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}