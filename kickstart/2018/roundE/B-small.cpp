#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t, n, m, p;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> m >> p;
        vector<string> pref(n+m);
        for (int i = 0; i < n+m; i++) {
            cin >> pref[i];
        }
        multimap<int, int> mmap;
        vector<int> v0(p, 0), v1(p, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                if (pref[i][j] == '0') v0[j]++;
                else v1[j]++; 
            }
        }
        // for (int i = 0; i < p; i++) {
        //     cout << v0[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < p; i++) {
        //     cout << v1[i] << " ";
        // }
        // cout << endl;
        int ss = pow(2, p);
        for (int i = 0; i < ss; i++) {
            bitset<10> bs = i;
            string s = bs.to_string();
            int a = 0;
            for (int j = 0; j < p; j++) {
                if (s[j+10-p] == '0') a += v1[j];
                else a += v0[j];
            }
            mmap.insert(make_pair(a, i));
        }
        set<string> forb;
        for (int i = n; i < n+m; i++) {
            forb.insert(pref[i]);
        }
        int ans = 0;
        multimap<int, int> :: iterator it = mmap.begin();
        // for (auto i = mmap.begin(); i != mmap.end(); i++) {
        //     cout << i->second << ", " << i->first << endl;
        // }
        for (int i = 0; i < 11; i++) {
            int cost = it->first;
            int num = it->second;
            // cout << num << ", " << cost << endl;
            bitset<10> bs = num;
            string s = bs.to_string();
            if (forb.find(s.substr(10-p, p)) == forb.end()) {
                ans = cost;
                // cout << "hello" << endl;
                break;
            }
            it++;
        }
        cout << "Case #" << c << ": " << ans;
        cout << endl;
    }
}