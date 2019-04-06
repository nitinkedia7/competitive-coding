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
const ld pi = 3.14159265;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int n, r;
    cin >> n >> r;
    ld a = 3.14159265358979323846;
    a = a/n;
     
    ld d = 1.0 - sin(a);
    ld ans = r;
    ans = ans * sin(a);
    ans = ans/d;
    cout << std::setprecision(15) << ans << endl;
    return 0;
}