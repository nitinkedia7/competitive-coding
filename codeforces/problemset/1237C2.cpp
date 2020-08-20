#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;
const int N = 50000, D = 3;

int p[N][3];

int solve(vector<int> ids, int k) {
    if (k == D) return ids[0];
    map<int,vector<int>> mp;
    for (auto &i : ids) {
        mp[p[i][k]].push_back(i);
    }
    vector<int> a;
    for (auto &[x, y] : mp) {
        int id = solve(y, k+1);
        if (id != -1) a.push_back(id);
    }
    for (int i = 0; i+1 < a.size(); i += 2) {
        cout << a[i] + 1 << " " << a[i+1] + 1 << '\n'; 
    }   
    return (a.size() % 2 == 1 ? a.back() : -1);
}

void sherlock(int t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }    
    vector<int> ids(n);
    iota(all(ids), 0);
    solve(ids, 0);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}