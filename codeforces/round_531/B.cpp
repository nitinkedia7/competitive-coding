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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), adj(5001, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        adj[v[i]]++;
    }

    vector<vector<int>> col(5001);
    int c = 1;
    bool flag = false;
    for (int i = 1; i < 5001; i++) {
        if (adj[i] > k) {
            cout << "NO" << endl;
            return 0;
        }
        for (int j = adj[i]; j > 0; j--) {
            col[i].pb(c);
            if (c == k) flag = true;
            c = (c)%k + 1;
        }
    }
    if (!flag) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << col[v[i]].back() << " ";
        col[v[i]].pop_back();
    }
    cout << endl;
    return 0;
}