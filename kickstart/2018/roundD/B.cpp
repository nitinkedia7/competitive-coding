#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    int n, k;
    int x1, x2, a, b, c, m;
    long long d;
    cin >> t;
    for (int count = 1; count <= t; count++) {
        cin >> n >> k;
        vector<int> p(n), h(n), x(k), y(k);
        cin >> x1 >> x2 >> a >> b >> c >> m;
        p[0] = x1;
        p[1] = x2;
        a = a%m;
        b = b%m;
        c = c%m;
        for (int i = 2; i < n; i++) {
            long long z = (a*1LL*p[i-1]) % m;
            z += (b*1LL*p[i-2]) % m;
            z = z%m;
            z += c;
            z = z%m;
            p[i] = z+1;
        }
        cin >> x1 >> x2 >> a >> b >> c >> m;
        h[0] = x1;
        h[1] = x2;
        a = a%m;
        b = b%m;
        c = c%m;
        for (int i = 2; i < n; i++) {
            long long z = (a*1LL*h[i-1]) % m;
            z += (b*1LL*h[i-2]) % m;
            z = z%m;
            z += c;
            z = z%m;
            h[i] = z+1;
        }
        cin >> x1 >> x2 >> a >> b >> c >> m;
        x[0] = x1;
        x[1] = x2;
        a = a%m;
        b = b%m;
        c = c%m;
        for (int i = 2; i < k; i++) {
            long long z = (a*1LL*x[i-1]) % m;
            z += (b*1LL*x[i-2]) % m;
            z = z%m;
            z += c;
            z = z%m;
            x[i] = z+1;
        }
        cin >> x1 >> x2 >> a >> b >> c >> m;
        y[0] = x1;
        y[1] = x2;
        a = a%m;
        b = b%m;
        c = c%m;
        for (int i = 2; i < k; i++) {
            long long z = (a*1LL*y[i-1]) % m;
            z += (b*1LL*y[i-2]) % m;
            z = z%m;
            z += c;
            z = z%m;
            y[i] = z+1;
        }
        vector<int> r(k, 0);
        // for each ballon from each tower
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {

            }
        }
    
        cout << "Case #" << count << ": ";
        cout << endl;
    }   
}