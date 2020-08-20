#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int b = 0, nb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') b++;
        else {  
            if (b == 0) nb++;
            else b--;
        }
    }    
    cout << nb << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
