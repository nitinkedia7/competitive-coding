#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int x = *max_element(v.begin(), v.end());
    sort(v.begin(), v.end());   
    int z = gcd(x - v[0], x - v[1]);
    for (int i = 2; i < n && v[i] < x; i++) {
        z = gcd(z, x - v[i]);
    }
    assert(z != 0);
    long long y = 0;
    for (int i = 0; i < n; i++) {
        y += (x - v[i]) / z;
    }
    cout << y << " " << z << endl;
}