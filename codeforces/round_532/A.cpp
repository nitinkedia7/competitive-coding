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
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int ans = 0, t = 0, s = 0;
    for (int b = 0; b < k; b++) {
        s = 0;
        t = 0;
        for (int i = 1; i <= n; i++) {
            if ((i - b + k) % k != 0) {
                if (v[i] == 1) {
                    t++;
                }
                else if (v[i] == -1) s++;
            }
        }
        ans = max(ans, abs(s-t));
    }
    cout << ans << endl;
    return 0;
}