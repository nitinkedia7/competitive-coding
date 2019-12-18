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

int scan(string &s, int start, int end, char y) {
	int i = 0;
	int c = 0;
	while (start + i < end) {
		if (s[start+i] == y) c++;
		i++;
	}
	return c;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	int n, b, f;
	for (int c = 1; c <= t; c++) {
		cin >> n >> b >> f;
		int no = n;

		int p = 1;
		while (p < n) p = 2*p; 
		n = p;

		int x = 2;
		string s(no, '1');
		vector<int> v;
		v.push_back(no-b);


		while (x <= n) { // = needs checking
 			char y = '1';
			// build s;
			for (int i = 0; i < no; i += n/x) {
				for (int j = i; j < min(no, i + n/x); j++) {
					s[j] = y;
				}
				if (y == '1')  y = '0';
				else y = '1';
			}
			cout << s << endl;
			string o;
			cin >> o;
			// y = '1';
			vector<int> v2;
			int k = 0;
			for (int i = 0; i < v.size(); i++) {
				v2.push_back(scan(o, k, k+v[i], '1'));
				v2.push_back(scan(o, k, k+v[i], '0'));
				k += v[i];
			}
			x = 2*x; 		
			v = v2;
			// for (int i = 0; i < v2.size(); i++) {
			// 	cout << v2[i] << ", ";
			// }	
			// cout << endl << x << endl;
		}

		for (int i = 0; i < no; i++) {
			if (v[i] == 0) {
				cout << i << " ";
			}
		}
		cout << endl;
		int ver;
		cin >> ver;
		if (ver == -1) {
			return 0;
		}
	}
	return 0;
}