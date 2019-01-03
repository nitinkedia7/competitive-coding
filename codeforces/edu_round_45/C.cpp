#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int bal(string s) {
    int o = 0;
    for (int j = 0; j < s.length(); j++) {
        if (s[j] == '(') o++;
        else o--;
        if (o < 0) return -1;
    }
    return o;
}

int main() {
    int n;
    cin >> n;
    string s[n];
    string r[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
        for (int j = 0; j < r[i].length(); j++) {
            if (r[i][j] == '(') r[i][j] = ')';
            else r[i][j] = '(';
        }
    }
    int s1[n], r1[n];
    for (int i = 0; i < n; i++) {
        s1[i] = bal(s[i]);
        r1[i] = bal(r[i]);
    }
    int array[300001];
    for (int i = 0; i < 300001; i++) {
        array[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] != -1) array[s1[i]]++;
    }
    // for (int i = 0; i < n; i++) cout << s1[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << r1[i] << " ";
    // cout << endl;

    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (r1[i] != -1) {
            count += array[r1[i]];
        }
    }
    cout << count << endl;
}