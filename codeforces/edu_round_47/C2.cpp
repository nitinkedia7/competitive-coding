#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int l = s.length();

    int i = 0, state = 0;
    int a = 0, b = 0, c = 0;
    vector<char> v;
    while (i < l) {
        if (state == 0) {
            if (s[i] == '0') a++;
            else if (s[i] == '1') b++;
            else if (s[i] == '2') {
                while (a) {
                    v.push_back('0');
                    a--;
                }
                while (b) {
                    v.push_back('1');
                    b--;
                }
                state = 1;
                c = 0;
            }
        }
        if (state == 1) {
            if (s[i] == '1') b++;
            else if (s[i] == '2') c++;
            else if (s[i] == '0') {
                while (b) {
                    v.push_back('1');
                    b--;
                }
                while (c) {
                    v.push_back('2');
                    c--;
                }
                state = 0;
                a = 1;
            }
        }
        if (i == l-1) {
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
        }
        i++;
    }
    for (int i = 0; i < s.length(); i++) {
        cout << v[i];
    }
    cout << endl;
}