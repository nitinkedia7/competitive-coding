#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> entry(n), exit(n);
    for (int i = 0; i < n; i++) cin >> entry[i];
    for (int i = 0; i < n; i++) cin >> exit[i];
    int f = 0, ans = 0;
    map<int,int> m; // car to entry pos 
    for (int i = 0; i < n; i++) {   
        m[entry[i]] = i;
    }
    vector<int> pr(n);
    for (int i = 0; i < n; i++) {
        ans += pr[i];
        int gl = m[exit[i]] + ans;
        cout << gl << " ";
        if (gl > i) {
            f++;
            ans++;
            pr[m[exit[i]]]--;
            cout << "fined";
        }
        cout << endl;
    }
    cout << f << endl;
}