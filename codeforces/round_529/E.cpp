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
    string s;
    cin >> s;
    vector<int> v(n, 0);
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            a++;
            v[i] = a;
        }
        else {
            a--;
            v[i] = a;
        }
    }
    vector<int> miv(n, v[n-1]);
    for (int i = n-2; i >= 0; i--) {
        miv[i] = min(v[i], miv[i+1]);
    }
    int ans = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (!flag) break;
        if (s[i] == '(') {
            if (miv[i] == 2 && v[n-1] == 2) ans++; 
        }
        if (s[i] == ')') {
            if (miv[i] == -2 && v[n-1] == -2) ans++; 
        }
        if (v[i] < 0) flag = false;
    }
    cout << ans << endl;
    return 0;
}