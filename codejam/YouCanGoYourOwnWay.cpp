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

	int t, n;
	string s;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cin >> n;
		cin >> s;
		cout << "Case #" << c << ": ";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'E') cout << 'S';
			else cout << 'E';
		}
		cout << endl;
	}
	return 0;
}