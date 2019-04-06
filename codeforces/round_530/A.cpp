
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

    int w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;

    for (int i = h; i >= 0; i--) {
        w += i;
        if (i == d1) {
            w = max(0, w-u1);
        }
        if (i == d2) {
            w = max(0, w-u2);
        }
    }
    cout << w << endl;
	return 0;
}