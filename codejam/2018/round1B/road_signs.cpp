#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<int> d(100), a(100), b(100), v(100);

void reset(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = 0;
    }
}

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}



void sherlock(int t) {
    int s;
    cin >> s;
    set<int> m, n;
    for (int i = 0; i < s; i++) {
        cin >> d[i] >> a[i] >> b[i];
        m.insert(d[i] + a[i]);
        n.insert(d[i] - b[i]);
    }
    int maxl = 0;
    set<pair<int,int>> ss;
    for (auto x : m) {
        for (auto y : n) {
            reset(v);
            for (int i = 0; i < s; i++) {
                if (d[i] + a[i] == x) v[i] = 1;
                if (d[i] - b[i] == y) v[i] = 1;
            }
            // find max run length
            int i = 0;
            while (i < s) {
                int pi = i;
                while (v[i] == 1) {
                    i++;
                }
                if (i - pi > maxl) {
                    maxl = i - pi;
                    ss.clear();
                    ss.insert({pi, i});
                }
                else if (i - pi == maxl) {
                    ss.insert({pi, i});
                } 
                i++;
            }
        }
    }
    
    cout << "Case #" << t << ": " << maxl << " " << ss.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}