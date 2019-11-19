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

void sherlock() {
    string s;
    cin >> s;
    if (s.length() == 1) {
        cout << 1 << endl;
        return;
    }
    // construct suffix array
    int n = s.length(), m = ceil(log2(n));    
    vector<vector<int>> v(m + 1, vector<int> (n));
    for (int i = 0; i < n; i++) {
        v[0][i] = s[i];
    }
    vector<tuple<int,int,int>> l(n); // rank, rank, index
    int cnt = 1;
    for (int j = 1; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            l[i] = {v[j-1][i], i + cnt < n ? v[j-1][i + cnt] : -1, i};
        }
        sort(l.begin(), l.end());
        for (int i = 0; i < n; i++) {
            int ind = get<2> (l[i]);
            v[j][ind] = i > 0 && (get<0> (l[i-1]) == get<0> (l[i])) && (get<1> (l[i-1]) == get<1> (l[i])) ?
                v[j][get<2>(l[i-1])] : i;
        }
        cnt *= 2;
    }
    // print(v[m]);
    vector<int> indexof(n), rankof(n), lcp(n, -1);
    for (int i = 0; i < n; i++) {
        rankof[i] = v[m][i]; // index to rank
        indexof[v[m][i]] = i; // rank to index
    }
    // construct LCP array
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rankof[i] == n - 1) {
            k = 0;
            lcp[n-1] = 0;
            continue;
        }
        int j = indexof[rankof[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) {
            k++;
        } 
        lcp[rankof[i]] = k;
        if (k > 0) k--;
    }
    // print(lcp);
    ll c = n * 1LL * (n + 1);
    c /= 2;
    for (int i = 0; i < n; i++) {
        assert(lcp[i] != -1);
        c -= lcp[i];
    }
    cout << c << endl;
    v.clear();
    s.clear();
    lcp.clear();
    rankof.clear();
    indexof.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock();
    return 0;
}