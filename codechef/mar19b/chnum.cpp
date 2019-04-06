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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) a++;
            else b++;
        }
        if (a == 0) a = b;
        if (b == 0) b = a;
        cout << max(a,b) << " " << min(a, b) << endl;
    }
    return 0;
}