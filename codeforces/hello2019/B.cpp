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


bool recur(vector<int> &v, int i, int n, int sum) {
    if (i == n) {
        if (sum % 360 == 0) return true;
        else return false;
    } 
    return (recur(v, i+1, n, sum+v[i]) || recur(v, i+1, n, sum-v[i]));
} 

int main ()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    if (recur(v, 0, n, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;

	return 0;
}