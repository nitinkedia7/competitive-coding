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
const int N = 1e6 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin >> t;
    vector<bool> isPrime(N, 1);
    vector<int> primes;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 0; i < N; i++) {
        if (isPrime[i]) {
            primes.pb(i);
            int ofs = 2 * i;
            while (ofs < N) {
                isPrime[ofs] = 0;
                ofs += i;
            }
        }
    }
    for (; t > 0; t--) {
        int n;
        cin >> n;
        vector<ll> ans;
        for (int i = 0; i < n; i++) {
            if (i < n-1) {
                ans.pb(primes[i] * 1LL * primes[i+1]);
            }
            else {
                ans.pb(primes[i] * 1LL * 2);
            }
        }
        for (int i = 0; i < n; i++) {
            // assert(ans[i] <= 1e9);
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}