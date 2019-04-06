#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = mp(a-1, b-1);
    }

    vector<int> pos(n, -1);
    int d = n;
    int p1 = 0, i = 0;
    while (d > 0) {
        pos[i] = p1;
        a = v[p1].f;
        b = v[p1].s;
        if (v[b].f == a || v[b].s == a) {
            pos[(i+2) % n] = a;
            pos[(i+1) % n] = b;
            i = (i+3) % n;
            p1 = v[b].f + v[b].s - a; 
        }
        else {
            pos[(i+2) % n] = b;
            pos[(i+1) % n] = a;
            i = (i+3) % n;
            p1 = v[a].f + v[a].s - b; 
        }
        d -= 3;
    }
    for (int i = 0; i < n; i++) cout << pos[i] + 1 << " ";
    cout << endl;
    return 0;
}