#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void print(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

ll power(ll a, ll b, ll mod){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}	
 
ll modular_inverse(ll n, ll mod){
	return power(n, mod-2, mod);
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> m;
        vector<int> fac(2*n+1, 1);
        for (int i = 1; i <= 2*n; i++) {
            ll num = (1LL * i * fac[i-1]);
            fac[i] = num % 1000000007;
        }
        // print(fac);
        vector<int> com(m+1, 1);
        for (int i = 1; i <= m; i++) {
            ll num = 1LL * com[i-1] * (m-i+1);
            num = num % 1000000007;
            ll num2 = modular_inverse(i, 1000000007);
            num = (num * num2) % 1000000007;
            com[i] = num % 1000000007;
        } 
        // print(com);
        vector<int> pow2(m+1, 1);
        for (int i = 1; i <= m; i++) {
            pow2[i] = (pow2[i-1]*2) % 1000000007;
        }
        // print(pow2);
        ll ans = 0, term = 0;
        for (int i = 0; i <= m; i++) {
            term = com[i];
            term = term * fac[2*n-i];
            term = term % 1000000007;
            term = term * pow2[i];
            term = term % 1000000007;
            if (i % 2 == 1) {
                term = -1 * term;
                term += 1000000007;
            } 
            // cout << i << ", " << (term % 1000000007) << endl;
            ans += (term % 1000000007);
            ans = ans % 1000000007;
        }
        cout << "Case #" << c << ": " << ans;
        cout << endl;
    }
}