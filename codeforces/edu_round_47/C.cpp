#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int x[m], d1[m];
    long double a = 0, b = 0;
    long double d;
    if (n % 2 == 0) {
        d = n;
        d = d/4;
    }
    else {
        d = n*n - 1;
        d = d/(2*n);
    }
    long double e = n - 1;
    e = e/2;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> d1[i];
        a += x[i];
        if (d1[i] > 0) {
            b += d1[i] * e;
        }
        else b += d1[i] * d;
    }
    long double c = a + b;
    printf("%Lf", c);
    // cout << c << endl; 
}