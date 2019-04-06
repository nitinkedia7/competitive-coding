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

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int n;
    cin >> n;
    // int a = sqrt(n);
    // if (a * a == n) {
    //     cout << 2*a << endl;
    // }  
    // else if (a * (a + 1) == n) {
    //     cout << 2*a + 1 << endl;
    // }
    // else 
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = min(ans, i + n/i);
        } 
        else {
            ans = min(ans, i + (n/i) + 1);
        }
    }
    cout << ans << endl;
	return 0;
}