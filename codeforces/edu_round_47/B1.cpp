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
        if (s[i] == '1') {
            b++;
            int j = i+1;
            while (j < s.length()) {
                if (s[j] == '1') b++;
                else if (s[j] == '0') a++;
                if (s[j] == '2') {
                    while (a) {
                        v.push_back('0');
                        a--;
                    }
                    while (b) {
                        v.push_back('1');
                        b--;
                    }
                    i = j;
                    c = 1;
                    break;
            }

        }
        if (s[i] == '2') {
           c++;
           

        }
        i++;
    }
    for (int i = 0; i < s.length(); i++) {
        cout << v[i];
    }
    cout << endl;
}