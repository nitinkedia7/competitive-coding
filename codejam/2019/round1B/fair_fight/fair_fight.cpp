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
        if (vl > vr) seg[i] = l;
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
            l++;
        }
        l /= 2;
        if (r % 2 == 1) {
            r--;
            if (v[seg[r]] > v[maxi]) maxi = seg[r];
        }
        r /= 2;
    }
    return maxi;
}


vector<int> find_left_bound(int n, vector<int> &c, vector<int> &d, int val) {    
    vector<int> seg = build(d, n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        // for each index apply binary search in [0, i]
        // to find largest index s.t. max(l..i) < val
        int l = 0;
        int r = i;
        int x = c[i] + val;
        // cout << endl;
        while (l <= r) {
            int mid = (l + r) / 2;
            int qv = d[query(seg, d, n, mid, i + 1)];
            // cout << l << " " << r << "  " << qv << endl;
            if (qv >= x) {
                l = mid + 1;
            } 
            else r = mid - 1;
        }
        // cout << l << " " << r << endl;
        // l contains upper_bound
        // cout << i << " " << l << endl << endl;
        ans[i] = i + 1 - l;
    }
    // cout << endl;
    return ans;
}

vector<int> just_ge(int n, vector<int> &c) {
    // just greater or equal to left using stack
    vector<int> v(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && c[s.top()] < c[i]) {
            s.pop();
        }
        v[i] = (s.empty() ? i + 1 : i - s.top());
        s.push(i);
    }
    return v;
}

vector<int> just_g(int n, vector<int> &c) {
    // just greater or equal to left using stack
    vector<int> v(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && c[s.top()] <= c[i]) {
            s.pop();
        }
        v[i] = (s.empty() ? i + 1 : i - s.top());
        s.push(i);
    }
    return v;
}

ll count(int n, vector<int> &c, vector<int> &d, vector<int> &l1, vector<int> &r1, int val) {
    vector<int> l = find_left_bound(n, c, d, val);
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());
    vector<int> r = find_left_bound(n, c, d, val);
    
    // print(l);
    // print(l1);
    // print(r);
    // print(r1);

    ll x = 0;
    for (int i = 0; i < n; i++) {
        // cout << min(l[i], l1[i]) * min(r[n - 1 - i], r1[n - 1 - i]) << " ";
        x += min(l[i], l1[i]) * min(r[n - 1 - i], r1[n - 1 - i]);
    }
    // cout << "   " << x << endl << endl;
    return x; 
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

    vector<int> l1 = just_ge(n, c);
    reverse(c.begin(), c.end());
    vector<int> r1 = just_g(n, c);
    reverse(c.begin(), c.end());
    ll x = count(n, c, d, l1, r1, k + 1);
    ll y = count(n, c, d, l1, r1, -1 * k);
    cout << "Case #" << t << ": " <<  x - y << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}