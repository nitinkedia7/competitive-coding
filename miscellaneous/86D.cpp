#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int sqn;
ll count1[1000001];
// pair<pair<int,int>,int>

bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b) {
    int l1 = a.first.first / sqn, l2 = b.first.first / sqn;
    if (l1 == l2) return a.first.second < b.first.second;
    return (l1 < l2);
}

void add(ll v, ll &sum) {
    ll c = count1[v];
    sum -= c * c * v;
    c = ++count1[v];
    sum += c * c * v;
}

void remove(ll v, ll &sum) {
    ll c = count1[v];
    sum -=  c * c * v;
    c = --count1[v];
    sum += c * c * v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, t;
    cin >> n >> t;
    sqn = 1000;
    ll v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l, r;
    vector<pair<pair<int,int>,int>> q(t);
    for (int i = 0; i < t; i++) {
        cin >> l >> r;
        l--;
        r--;
        q[i] = {{l, r}, i};
    }
    sort(q.begin(), q.end(), comp);
    ll ans[t];
    ll sum = 0, cl = 0, cr = -1;
    int id;
    for (int i = 0; i < t; i++) {
        l = q[i].first.first;
        r = q[i].first.second;
        id = q[i].second;
        // cout << l << "," << r << " ";
         while (cr < r) {
            cr++;
            add(v[cr], sum);
        }
        while (cr > r) {
            remove(v[cr], sum);
            cr--;
        }
        while (cl < l) {
            remove(v[cl], sum);
            cl++;
        }
        while (cl > l) {
            cl--;
            add(v[cl], sum);
        }
        ans[id] = sum;
    }
    for (int i = 0; i < t; i++) {
        printf("%lld\n", ans[i]);
        // cout << ans[i] << endl;
    }
    return 0;
}