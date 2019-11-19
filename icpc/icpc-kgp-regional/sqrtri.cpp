#include <bits/stdc++.h>
using namespace std;

bool basex(int a, int b, int x, int y) {
    float p = (x * (a-y));
    p = p / b;
    float q = (x + b - a)*(a - y - b);
    q = q / b;
    q += (x + b);
    if (p >= q) return true;
    else return false;
}


int main() {
    int t, a, b, x, y;
    cin >> t;
    for (; t > 0; t--) {
        cin >> a >> b >> x >> y;
        bool b1 = basex(a, b, x, y);
        bool b2 = basex(a, b, y, a-x-b);
        bool b3 = basex(a, b, a-y-b, x);
        bool b4 = basex(a, b, a-x-b, a-y-b);
        // cout << b1 << endl;
        // cout << b2 << endl;
        // cout << b3 << endl;
        // cout << b4 << endl;
        if (b1 || b2 || b3 || b4) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    } 
}