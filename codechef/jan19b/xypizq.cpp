#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n, type, x, y, z;
        cin >> n >> type >> x >> y >> z;

        ll de = 2 * 1LL * n + 1; // al = pi/2n+1
        ll nu = -1;

        if (type == 1) {
            if (y > x) {
                if (z > y) {
                    nu = 2 * 1LL * n - x - 1;
                }
                else {
                    nu = x;
                }
            }
            else { // y < x
                if (z > y) {
                    nu = x;
                }
                else {  
                    nu = 2*1LL*n - x + 3;
                }
            }
        }
        else if (type == 2 || type == 4) {
            if (y > x) {
                if (z > y) {
                    nu = 2 * 1LL * (n-x) -1;
                }
                else {
                    nu = 0;
                }
            }
            else {
                if (z > y) {
                    nu = 0;
                }
                else {
                    nu = 2 * 1LL * (n-x) + 3;
                }
            }
        }
        else {
            if (y > x) {
                if (z > y) {
                    nu = 2 * 1LL * n - x + 1;
                }
                else {
                    nu = x;
                }
            }
            else {
                if (z > y) {
                    nu = x;
                }
                else {
                    nu = 2 * 1LL * n - x + 1;
                }
            }
        }
        ll g = gcd(nu, de);
        nu = nu/g;
        de = de/g;
        cout << nu << " " << de << endl;
    }
    return 0;
}