#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int swap(string &s, int i, int j) { // i --> j
    int c = 0;
    char temp;
    while (i < j) {
        temp = s[i];
        s[i] = s[i+1];
        s[i+1] = temp;
        c++;
        i++;
    }
    return c;
}

int isPossible(string &s) {
    int n = s.length();
    vector<int> count(26);
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    int x = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2) {
            x++;
        } 
    }
    return n % 2 == x;
}

void sherlock(string s) {
    if (!isPossible(s)) {
        cout << "Impossible" << endl;
        return;
    }
    int n = s.length();
    int swaps = 0;
    for (int i = 0; i < n / 2; i++) {
        bool found = false;
        for (int j = n - 1 - i; j > i; j--) {
            if (s[j] == s[i]) {
                found = true;
                swaps += swap(s, j, n - 1 - i);
                break;
            }
        }
        if (found == false) {
            swaps += swap(s, i, n / 2);
            i--;
        }
        cout << s << endl;
    }
    cout << swaps << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (1) {
        cin >> s;
        if (s[0] == '0') break;
        sherlock(s);
        s.clear();
    }
    return 0;
}