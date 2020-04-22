#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
vector<int> v(1001, 0);


void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> x(n), c(n);
    vector<int> count(12);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        c[i] = v[x[i]];
        count[v[x[i]]] = 1;
    }
    int m = 0;
    vector<int> z(12);
    for (int i = 1; i <= 11; i++) {
        if (count[i] > 0) {
            m++;
            z[i] = m;
        }
    }
    
    cout << m << endl;
    for (int i = 0; i < n; i++) {
        cout << z[c[i]] << " ";
    }
    cout << endl;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
} 

void police() {
    for (int i = 4; i <= 1000; i++) {
        if (isPrime(i)) continue;
        vector<int> color(12);
        for (int j = 4; j < i; j++) {
            if (isPrime(j)) continue;
            if (gcd(j, i) == 1) {
                color[v[j]] = 1;
            }
        }
        for (int c = 1; c <= 11; c++) {
            if (color[c] == 0) {
                v[i] = c;
                break;
            }
        }
        color.clear();
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    police();
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}