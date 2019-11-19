#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == 'a' && s[i+1] == 'a') {
            s[i] = 'b';
            ans++;
        }
        else if (s[i] == 'b' && s[i+1] == 'b') {
            s[i] = 'a';
            ans++;
        }
    }
    cout << ans << endl;
    cout << s << endl;
}