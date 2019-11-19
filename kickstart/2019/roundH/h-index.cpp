#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > ms.size()) {
            ms.insert(v[i]);
            while (!ms.empty() && *ms.begin() < ms.size()) {
                ms.erase(ms.begin());
            }  
        }
        else {
            if (!ms.empty() && *ms.begin() < v[i]) {
                ms.erase(ms.begin());
                ms.insert(v[i]);
            }
        }
        ans[i] = ms.size();
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }    
    cout << endl;
    ms.clear();
    v.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}