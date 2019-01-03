#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int p = 0, i = 0;
    int a = 0, b = 0, c = 0;
    vector<char> v;
    while (i < s.length()) {
        if (s[i] == '0') a++;
        if (s[i] == '1') b++;
        if (s[i] == '2') c++;

        if (i == s.length() - 1) {
            while (a) {
                v.push_back('0');
                a--;
            }
            while (b) {
                v.push_back('1');
                b--;
            }
            while (c) {
                v.push_back('2');
                c--;
            }
            p = i;
        }
        else if (s[i] == '0' && s[i+1] == '2') {
            while (a) {
                v.push_back('0');
                a--;
            }
            while (b) {
                v.push_back('1');
                b--;
            }
            while (c) {
                v.push_back('2');
                c--;
            }
            p = i;

        }
        else if (s[i] == '2' && s[i+1] == '0') {
            while (a) {
                v.push_back('0');
                a--;
            }
            while (b) {
                v.push_back('1');
                b--;
            }
            while (c) {
                v.push_back('2');
                c--;
            }
            p = i;
        }
        i++;
    }
    for (int i = 0; i < s.length(); i++) {
        cout << v[i];
    }
    cout << endl;
}