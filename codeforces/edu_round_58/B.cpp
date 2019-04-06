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
    string s;
    cin >> s;
    vector<char> v;
    int s1 = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            s1 = i;
            break;
        }
    }
    if (s1 == -1) {
        cout << -1 << endl;
        return 0;
    }
    int s2 = -1;
    for (int i = s1; i < s.length(); i++) {
        if (s[i] == ':') {
            s2 = i;
            break;
        }
    }
    if (s2 == -1) {
        cout << -1 << endl;
        return 0;
    }
    int e1 = -1;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ']') {
            e1 = i;
            break;
        }
    }
    if (e1 == -1) {
        cout << -1 << endl;
        return 0;
    }
    int e2 = -1;
    for (int i = e1; i >= 0; i--) {
        if (s[i] == ':') {
            e2 = i;
            break;
        }
    }
    if (e2 == -1) {
        cout << -1 << endl;
        return 0;
    }
    if (s2 >= e2) {
        cout << -1 << endl;
        return 0;
    }
    int l = 0;
    for (int i = s2; i <= e2; i++) {
        if (s[i] == '|') l++;
    }
    cout << l+4 << endl;
    // int a = 0;
    // for (int i = 0; i < s.length(); i++) {
    //     if (a == 0 && s[i] == '[') {
    //         v.pb(s[i]);
    //         a++;
    //     }
    //     if (a == 1 && s[i] == ':') {
    //         v.pb(s[i]);
    //         a++;
    //     }
    //     int c = -1;
    //     if (a == 2 && ) 
    // }
    return 0;
}