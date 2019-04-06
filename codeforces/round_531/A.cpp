#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int n;
    cin >> n;
    ll sum = n;
    sum = sum * (n+1);
    sum = sum/2;
    if (sum % 2 == 0) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}