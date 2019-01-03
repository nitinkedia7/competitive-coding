#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < n; i++) pq.push(v[i]);
        int d = 0;
        int ans = 0;
        while (!pq.empty()) {
            int i = 0;
            while (i < k && !pq.empty()) {
                if (d < pq.top()) {
                    ans++;
                    i++;
                }
                pq.pop();
            }
            d++;
        }
        cout << "Case #" << c << ": " << ans;
        // cout << "Case #" << c << ": " << ans << " " << d+1;        
        cout << endl;
    }
}