#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool isPrefix(string p, string s) {
    if (p.length() > s.length()) return false;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] != s[i]) return false;
    } 
    return true;
}

ull exponentiation(ull base, ull exp) 
{ 
    if (exp == 0) 
        return 1; 
  
    if (exp == 1) 
        return base; 
  
    long int t = exponentiation(base, exp / 2); 
    t = (t * t); 
  
    // if exponent is even value 
    if (exp % 2 == 0) 
        return t; 
  
    // if exponent is odd value 
    else
        return ((base) * t); 
} 

int main() {
    int t;
    int n, p;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> p;
        vector<string> v(p);
        for (int i = 0; i < p; i++) {
            cin >> v[i];
        }
        vector<bool> l(p, true);
        sort(v.begin(), v.end());
        for (int i = 0; i < p; i++) {
            if (!l[i]) continue;
            for (int j = i+1; j < p; j++) {
                if (!l[j]) continue;
                if (isPrefix(v[i], v[j])) {
                    // cout << v[i] << " " << v[j] << endl;
                    l[j] = false;
                }
            }
        }
        // for (int i = 0; i < p; i++) {
        //     cout << v[i] << " " << l[i] << endl;
        // }
        ull ways = exponentiation(2, n);
        for (int i = 0; i < p; i++) {
            if (l[i]) {
                ways -= exponentiation(2, n-v[i].length());
            }
        }

        cout << "Case #" << c << ": " << ways;
        cout << endl;
    }
}