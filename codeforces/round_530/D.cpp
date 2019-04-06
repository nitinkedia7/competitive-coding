#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void print(vector<int> &v, int n) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> par(n+1, -1);
    int p;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        adj[p].pb(i);
        par[i] = p;
    }
    vector<int> s(n+1), a(n+1, -1);
    for (int i = 1; i <= n; i++) cin >> s[i];

    // print(s, s.size());
    // print(a, a.size());
    if (s[1] < 0) {
        cout << -1 << endl;
        return 0;
    }
    a[1] = s[1];
    queue<int> q;
    queue<int> q2;
    q.push(1);
    q2.push(1);

    while(!q.empty()) {
        int u = q.front();
        int h = q2.front();
        q2.pop();
        q.pop();
        if (h % 2 == 0 && s[u] != -1) {
            cout << -1 << endl;
            return 0;
        }
        if (h % 2 == 1 && s[u] < 0) {
            cout << -1 << endl;
            return 0;   
        }

        if (adj[u].size() == 0) {
            if (s[u] == -1) {
                a[u] = 0;
                s[u] = s[par[u]];
            }
            else if (u != 1) {
                int val = s[u] - s[par[u]];
                if (val < 0) {
                    cout << -1 << endl;
                    return 0;
                }
                else a[u] = val;
            }
        }
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            // if (s[u] == -1) {
            if (h % 2 == 0) {
                int val = s[v] - s[par[u]];
                if (val < 0) {
                    cout << -1 << endl;
                    return 0;
                }
                if (a[u] == -1) a[u] = val;
                else a[u] = min(val, a[u]); 
                s[u] = s[par[u]] + a[u];
            }
            else if (u != 1) {
                int val = s[u] - s[par[u]];
                if (val < 0) {
                    cout << -1 << endl;
                    return 0;
                }
                else a[u] = val;
            }
            q.push(v);
            q2.push(h+1);
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        assert(a[i] > -1);
        sum += a[i];
    }
    cout << sum << endl;
	return 0;
}