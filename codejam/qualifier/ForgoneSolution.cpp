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

void printLeading(string &s) {
	int i = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] != '0') break;
	}
	for (; i < s.length(); i++) {
		cout << s[i];
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	string n;
	for (int c = 1; c <= t; c++) {
		cin >> n;
		string b = n;
		for (int i = 0; i < n.length(); i++) {
			if (b[i] == '4') {
				b[i] = '2';
				n[i] = '2';
			}
			else b[i] = '0';
		}
		cout << "Case #" << c << ": ";
		printLeading(n);
		cout << " ";
		printLeading(b);
		cout << endl;
	}	

	return 0;
}