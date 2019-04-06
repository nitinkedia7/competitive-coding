#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    char el;
    cin >> t >> el;
    string s;
    for (; t > 0; t--) {
        bool f = false;
        getline(cin, s);
        int l = s.length();
        for (int i = 0; i < l-2; i++) {
            bool a = false, b = false, c = false;
            if (s[i] == 'n' && s[i+1] == 'o'  && s[i+2] == 't') {
                a = true;
            }
            if (i == 0) b = true;
            else if (s[i-1] == ' ') b = true;

            if (i == l-3) c = true;
            else if (s[i+3] == ' ') c = true;

            if (a && b && c) f = true;
        }
        if (f) cout << "Real Fancy" << endl;
        else cout << "regularly fancy" << endl;
    }
    return 0;
}