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
    string s;
    int k;
    cin >> s >> k;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*') c++;
        else if (s[i] == '?') b++;
        else a++;
    }
    a = a - (b + c);
    // cout << a << ", " << b << ", " << c << endl; 

    vector<pair<char, char>> v;
    for (int i = 0; i < s.length(); i++) {
        if (i != s.length()-1) {
            if (s[i] != '*' && s[i] != '?') {
                if (s[i+1] == '*') v.pb(mp(s[i], '*'));
                else if (s[i+1] == '?') v.pb(mp(s[i], '?'));
                else v.pb(mp(s[i], '0'));
            }
        }
        else {
           if (s[i] != '*' && s[i] != '?') {
                v.pb(mp(s[i], '0'));
            }
        }
    } 

    if (a > k) {
        cout << "Impossible" << endl;
        return 0;
    }
    else {
        if (c > 0) {
            // possible since one flake exists
            bool flag = true;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].s == '0') cout << v[i].f;
                else if (v[i].s == '*' && flag) {
                    for (int j = 0; j < k-a; j++) cout << v[i].f; 
                    flag = false;
                }
            }

        }
        else if (a+b >= k) {
            // possible
            int count = a;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].s == '0') cout << v[i].f;
                else if (v[i].s == '?' && count < k) {
                    count++;
                    cout << v[i].f;
                }
            }
        }
        else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << endl;
	return 0;
}