#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int main() {
    int t, n;
    cin >> t;
    char a;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v.pb(a-'0');
        }
        int csum = 0, msum = 0;
        int k = (n+1)/2;
        for (int i = 0; i < k; i++) csum += v[i];
        msum = csum;
        for (int i = 1; i <= n-k; i++) {
            csum = csum - v[i-1] + v[i+k-1];
            msum = max(csum, msum);
        }
        cout << "Case #" << c << ": " << msum; 
        cout << endl;
    }
}