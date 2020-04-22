#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }
    vector<int> start(m);
    for (int i = 0; i < m; i++) {
        if (n - l[i] < i) {
            cout << -1 << endl;
            return;
        }
        start[i] = i;
    }
    // print(start);
    int i = m-1;
    int end = n-1;
    // try to slide forward
    while (i >= 0) {
        int r = start[i] + l[i] - 1;
        if (r >= end) {
            end = -1;
            break;
        }
        start[i] = end - l[i] + 1;
        end = start[i] - 1;
        i--;
    }
    // print(start);
    // cout << end << endl;
    if (end >= 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        cout << start[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}