#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<int> d(100000), a(100000), b(100000);

void reset(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) v[i] = 0;
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

pair<int,int> find_length(int l, int r, int m, int n) {
    int mid = (l + r) / 2;
    pair<int,int> ans;
    int i;
    for (i = mid + 1; i <= r; i++) {
        if (d[i] + a[i] != m && d[i] - b[i] != n) {
            break;
        }
    }
    ans.second = i - 1;
    for (i = mid - 1; i >= l; i--) {
        if (d[i] + a[i] != m && d[i] - b[i] != n) {
            break;
        }
    }
    ans.first = i + 1;
    return ans;
}

pair<int,int> divide(int l, int r) {
    if (l > r) return {0, 0};
    int m = (l + r) / 2;
    
    int n1 = INT_MAX, n2 = INT_MAX, m1 = INT_MAX, m2 = INT_MAX;
    for (int i = m+1; i <= r; i++) {
        if (d[i] + a[i] != d[m] + a[m]) {
            n1 = d[i] - b[i];
            break;
        }
    }
    for (int i = m-1; i >= l; i--) {
        if (d[i] + a[i] != d[m] + a[m]) {
            n2 = d[i] - b[i];
            break;
        }
    }
    for (int i = m+1; i <= r; i++) {
        if (d[i] - b[i] != d[m] - b[m]) {
            m1 = d[i] + a[i];
            break;
        }
    }
    for (int i = m-1; i >= l; i--) {
        if (d[i] - b[i] != d[m] - b[m]) {
            m2 = d[i] + a[i];
            break;
        }
    }
    vector<pair<int,int>> v(4);
    v[0] = find_length(l, r, d[m] + a[m], n1);
    v[1] = find_length(l, r, d[m] + a[m], n2);
    v[2] = find_length(l, r, m1, d[m] - b[m]);
    v[3] = find_length(l, r, m2, d[m] - b[m]);
    int maxl = 0, maxc = 0;
    for (int i = 0; i < 4; i++) {
        bool repeat = false;
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) repeat = true;
        }
        if (repeat) continue;
        int len = v[i].second - v[i].first + 1;
        if (len > maxl) {
            maxl = len;
            maxc = 1;
        }
        else if (len == maxl) maxc++;
    }
    pair<int,int> left = divide(l, m-1);
    if (left.first > maxl) {
        maxl = left.first;
        maxc = left.second;
    }
    else if (left.first == maxl) maxc += left.second;
    left = divide(m+1, r);
    if (left.first > maxl) {
        maxl = left.first;
        maxc = left.second;
    }
    else if (left.first == maxl) maxc += left.second;
    return {maxl, maxc};
}


void sherlock(int t) {
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> d[i] >> a[i] >> b[i];
    }
    pair<int,int> ans = divide(0, s-1);    
    cout << "Case #" << t << ": " << ans.first << " " << ans.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}