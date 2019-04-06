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
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') a++;
        if (s[i] == '1') b++;
        if (s[i] == '2') c++;
    }
    int k = n/3;

    if (a > k) {
        if (c < k) {
            int d = min(a-k, k-c);
            int i = n-1;
            while (d > 0 && i >= 0) {
                if (s[i] == '0') {
                    s[i] = '2';
                    d--;
                }
                i--;
            }
        }
        if (b < k) {
            int d = min(a-k, k-b);
            int i = n-1;
            while (d > 0 && i >= 0) {
                if (s[i] == '0') {
                    s[i] = '1';
                    d--;
                }
                i--;
            }
        }
    }
    if (b > k) {
        if (a < k) {
            int d = min(b-k, k-a);
            int i = 0;
            while (d > 0 && i < n) {
                if (s[i] == '1') {
                    s[i] = '0';
                    d--;
                }
                i++;
            }
        }
        if (c < k) {
            int d = min(b-k, k-c);
            int i = n-1;
            while (d > 0 && i >= 0) {
                if (s[i] == '1') {
                    s[i] = '2';
                    d--;
                }
                i--;
            }
        }
    } 
    if (c > k) {
        if (a < k) {
            int d = min(c-k, k-a);
            int i = 0;
            while (d > 0 && i < n) {
                if (s[i] == '2') {
                    s[i] = '0';
                    d--;
                }
                i++;
            }
        }
        if (b < k) {
            int d = min(c-k, k-b);
            int i = 0;
            while (d > 0 && i < n) {
                if (s[i] == '2') {
                    s[i] = '1';
                    d--;
                }
                i++;
            }
        }
    }
    cout << s << endl;
    return 0;
}