#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;

// void factorise(stack<pair<ll, ll>> &fac, ll n) {
//     ll c = 0;
//     while (n % 2 == 0) {
//         c++;
//         n = n/2;
//     }
//     fac.push(mp(2, c));

//     for (ll i = 3; i * i <= n; i += 2) {
//         c = 0;
//         while (n % i == 0) {
//             n = n/i;
//             c++;
//         }
//         // cout << "HELLO" << endl;
//         fac.push(mp(i, c));
//     }
//     if (n > 2) fac.push(mp(n, 1));
//     return;   
// }

int main ()
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

    int mod = 1e9+7;
    ll n, k;
    cin >> n >> k;
    stack<pair<ll, ll>> fac;
    // factorise(fac, n);
    ll c = 0;
    while (n % 2 == 0) {
        c++;
        n = n/2;
    }
    fac.push(mp(2, c));

    for (ll i = 3; i * i <= n; i += 2) {
        c = 0;
        while (n % i == 0) {
            n = n/i;
            c++;
        }
        // cout << "HELLO" << endl;
        fac.push(mp(i, c));
    }
    if (n > 2) fac.push(mp(n, 1));
    cout << "HELLO" << endl;
    ll ans = 1;


    // inverse for j = 1 to a
    vector<ll> inv(61, 1);
    // for (int i = 1; i < 50; i++) {
    //     inv[i] =  power(i, mod-2);
    // }
    for (int i = 1; i <= 50; ++i) {
        inv[i] = 1;
        while (inv[i] % i) {
            inv[i] += mod;
        }

        inv[i] /= i;
        assert(inv[i] < mod);
    }

    vector<ll> prev(200, 1);
    while (!fac.empty() ) {
        // cout << "HELLO" << endl;
        ll f = (fac.top()).f, a = (fac.top()).s;
        fac.pop();
        // cout << f << ", " << a << endl;

        // prev is for k = 0;
        ll fa = f % mod;
        for (int i = 1; i <= a; i++) {
            prev[i] = (prev[i-1] * fa) % mod;
        }


        for (int i = 1; i <= k; i++) {
            if (i != k) {
                for (int j = a; j >= 0; j--) {
                    ll val = 0;
                    for (int l = 0; l <= j; l++) {
                        val = (val + prev[l]);
                    }
                    val = val % mod;
                    val = (val * inv[j+1]) % mod;
                    prev[j] = val;
                }
            }
            else {
                for (int j = a; j >= a; j--) {
                    ll val = 0;
                    for (int l = 0; l <= j; l++) {
                        val = (val + prev[l]);
                    }
                    val = val % mod;
                    val = (val * inv[j+1]) % mod;
                    prev[j] = val;
                } 
            }
        }
        ans = ans * prev[a];
        ans = ans % mod;
    }
    cout << ans << endl;
	return 0;
}










