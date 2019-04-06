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

    int n, k, c = 0;
    cin >> n >> k;
    int m = n;
    vector<int> v;
    
    while (n > 0) {
        if (n % 2 == 1) {
            c++;
            v.pb(1);
        }
        else v.pb(0);
        n = n/2;
    }
    assert(n == 0);
    if (k < c || m < k) {
        cout << "NO" << endl;
        return 0;
    }
    int diff = k - c;
    vector<int> pow2(32, 1);
    for (int i = 1; i < 31; i++) pow2[i] = 2 * pow2[i-1]; 
    // for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "YES" << endl;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            if (diff == 0) {
                cout << pow2[i] << " ";
            }
            else {
                diff += 1;
                if (diff >= pow2[i]) {
                    for (int j = 0; j < pow2[i]; j++) {
                        cout << 1 << " ";
                    }
                    diff = diff-pow2[i];
                }
                else {
                    // cout << "HELLO" << endl;
                    int a = 0;
                    while (diff > pow2[a]) a++; // pow(2, a) >= diff

                    // cout << pow2[i] << ", " << pow2[a] << ", " << diff << endl;
                    int d = pow2[a], e = pow2[a-1];
                    int f = d - diff;
                    for (int j = 0; j < f; j++) {
                        cout << pow2[i]/pow2[a-1] << " ";
                    }
                    int lim = pow2[i] - f * (pow2[i]/pow2[a-1]);
                    lim = lim/(pow2[i]/pow2[a]);
                    for (int j = 0; j < lim; j++) {
                        cout << pow2[i]/pow2[a] << " ";
                    }
                    diff = 0;
                }
            }
        }
    } 
    cout << endl;
    return 0;
}