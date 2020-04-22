#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s, s1;
    cin >> s;    
    int b = 0;
    for (int i = 0; i < s.length(); i++) {
        int x = s[i] - '0';
        while (b < x) {
            s1.push_back('(');
            b++;
        }
        while (b > x) {
            s1.push_back(')');
            b--;
        }
        s1.push_back(s[i]);
    }
    while (b > 0) {
        s1.push_back(')');
        b--;
    }
    cout << "Case #" << t << ": " << s1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}