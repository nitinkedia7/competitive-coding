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
    int n;
    scanf("%d\n", &n);
    char t;
    int x, y;
    int mx = INT_MIN, my = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (i == n-1) scanf("%c %d %d", &t, &x, &y);
        else scanf("%c %d %d\n", &t, &x, &y);
        if (t == '+') {
           mx = max(mx, max(x, y));
           my = max(my, min(x, y));
        } 
        else if (t == '?') {
            int h = max(x, y);
            int w = min(x, y);
            if (h >= mx && w >= my) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}