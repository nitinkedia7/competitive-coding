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

vector<int> build(vector<int> &v, int n) {
    vector<int> seg(2 * n);
    for (int i = 0; i < n; i++) {
        seg[n + i] = i;
    }   
    int l, r, vl, vr;     
    for (int i = n - 1; i > 0; i--) {
        l = seg[2 * i];
        r = seg[2 * i + 1];
        vl = (l < n ? v[l] : INT_MIN);
        vr = (r < n ? v[r] : INT_MIN);
        if (vl >= vr) seg[i] = l;
        else seg[i] = r;  
    }   
    return seg;
}

int query(vector<int> &seg, vector<int> &v, int n, int l, int r) {
    // [l, r)
    l += n;
    r += n;
    int maxi = seg[l];
    while (l < r) {
        if (l % 2 == 1) { // if l is right child
            if (v[seg[l]] > v[maxi]) maxi = seg[l];
            if (v[seg[l]] == v[maxi] && seg[l] < maxi) maxi = seg[l];
            l++;
        }
        l /= 2;
        if (r % 2 == 1) {
            r--;
            if (v[seg[r]] > v[maxi]) maxi = seg[r];
            if (v[seg[r]] == v[maxi] && seg[r] < maxi) maxi = seg[r];

        }
        r /= 2;
    }
    return maxi;
}

ll getRange(int s, int e, int m, vector<int> &segd, vector<int> &d, int val) {
    int n = d.size();
    int l = s, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        int qv = d[query(segd, d, n, mid, m + 1)];
        if (qv >= val) l = mid + 1;
        else r = mid - 1; 
    }
    int left = (m - l + 1);
    l = m, r = e;
    while (l <= r) {
        int mid = (l + r) / 2;
        int qv = d[query(segd, d, n, m, mid + 1)];
        if (qv < val) l = mid + 1;
        else r = mid - 1;
    }
    // cout << "hi" << endl;
    int right = l - m;
    return left * 1LL * right;
}   

void divide(int l, int r, vector<int> &c, vector<int> &d, vector<int> &segc, vector<int> &segd, ll &ans, int k) {
    if (l > r) return;
    int n = c.size();
    int m = query(segc, c, n, l, r + 1);
    
    ll x = getRange(l, r, m, segd, d, c[m]+k+1);
    ll y = getRange(l, r, m, segd, d, c[m]-k);
    ans += x - y;
    // cout << l << " " << m << " " << r << "   " << x << " " << y << endl; 
    divide(l, m-1, c, d, segc, segd, ans, k);
    divide(m+1, r, c, d, segc, segd, ans, k);
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<int> segc = build(c, n);
    vector<int> segd = build(d, n);
    ll ans = 0;
    divide(0, n-1, c, d, segc, segd, ans, k);
    cout << "Case #" << t << ": " << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}