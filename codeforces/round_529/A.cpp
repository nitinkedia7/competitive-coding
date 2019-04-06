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
    int i = 0, j= 0;
    while (i < n) {
        cout << s[i];
        j++;
        i = (j * (j+1))/2;
    }
    cout << endl;

    return 0;
}