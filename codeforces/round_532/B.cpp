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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];
    set<pair<int, int>> ma;
    vector<int> mav(n+1, 0);
    for (int i = 1; i <= n; i++) ma.insert(mp(0, i));
    set<pair<int, int>>:: iterator itr;
    int r = 0;
    for (int i = 0; i < m; i++) {
        //update
        itr = ma.find(mp(mav[v[i]], v[i]));
        ma.erase(itr);
        mav[v[i]]++;
        ma.insert(mp(mav[v[i]], v[i]));
        // check
        itr = (ma.begin());
        if ((*itr).f >= r+1) {
            cout << '1';
            r++;
        }
        else cout << '0';
    }
    cout << endl;
    return 0;
}