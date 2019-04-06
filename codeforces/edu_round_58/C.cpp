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
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        int a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v[i] = mp(a, b);
        }
        multimap<pair<int, int>, int> m;
        for (int i = 0; i < n; i++) {
            m.insert(make_pair(v[i], 0));
        } 
        multimap<pair<int, int>, int> :: iterator itr;
        int x = 1;
        int q = INT_MIN;
        bool f = false;
        for (itr = m.begin(); itr != m.end(); ++itr) {
            if (itr == m.begin()) {
                (*itr).s = x;
            }
            else {
                int r = ((*itr).f).f;
                int s = ((*itr).f).s;
                if (r > q) {
                    x = x%2 + 1;
                    if (x == 2) f = true;
                    (*itr).s = x;
                }
                else {
                    (*itr).s = x;
                }
            }
            // p = max(p, ((*itr).f).f);
            q = max(q, ((*itr).f).s);
        }
        if (!f) cout << -1 << endl;
        else {
            for (int i = 0; i < n; i++) {
                cout << (*(m.lower_bound(v[i]))).s << " ";
            }
            cout << endl;
        }

    }
    return 0;
}