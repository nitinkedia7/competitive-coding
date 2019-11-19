#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ma = *max_element(v.begin(), v.end());
    int mi = *min_element(v.begin(), v.end());
    if (2 * mi >= ma) {
        for (int i = 0; i < n; i++) {
            cout << -1 << " ";
        }
        cout << endl;
        return 0;
    }
    int i = 0, j = 1 % n;
    multiset<int, greater<int>> ms;
    ms.insert(0);
    ms.insert(v[0]);
    int cnt = 1;
    while (i < n) {
        // expand
        while (2 * v[j] >= *ms.begin()) {
            ms.insert(v[j]);
            j = (j + 1) % n;
            cnt++;
        }   
        ans[i] = cnt;
        cout << ans[i] << " ";
        if (ms.find(v[i]) != ms.end()) ms.erase(ms.find(v[i]));
        else cout << i << " problem ";
        i++;
        cnt--;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << ans[i] << " ";
    // }
    cout << endl;
    return 0;
}