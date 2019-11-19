#include <bits/stdc++.h>
using namespace std;

vector<int> v(5);

tuple<int,int,int,int,int> makeTuple() {
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> v[i];
    }
    for (int i = s; i < 5; i++) {
        v[i] = 0;
    }
    sort(v.begin(), v.end());
    return {v[0], v[1], v[2], v[3], v[4]};
}

long long np2(int n) {
    if (n <= 1) return 0;
    long long x = n * 1LL * (n-1);
    return x;
}

tuple<int,int,int,int,int> super(tuple<int,int,int,int,int> &t) {
    tuple<int,int,int,int,int> ans = t;
    if (get<0>(t) == 0) get<0>(ans) = 1001;
    if (get<1>(t) == 0) get<1>(ans) = 1001;
    if (get<2>(t) == 0) get<2>(ans) = 1001;
    if (get<3>(t) == 0) get<3>(ans) = 1001;
    if (get<4>(t) == 0) get<4>(ans) = 1001;
    return ans;
}

void print(vector<tuple<int,int,int,int,int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << get<0> (v[i]) << " ";
        cout << get<1> (v[i]) << " ";
        cout << get<2> (v[i]) << " ";
        cout << get<3> (v[i]) << " ";
        cout << get<4> (v[i]) << endl;
    }
} 

void sherlock(int c) {
    int n, s;
    cin >> n >> s;
    vector<tuple<int,int,int,int,int>> sset;
    for (int i = 0; i < n; i++) {
        sset.push_back(makeTuple());
    }
    sort(sset.begin(), sset.end());
    print(sset);
    cout << endl;
    // cout << sset.size() << endl;
    long long ans = 0;
    int i = 0, j = 0, k = 0;
    tuple<int,int,int,int,int> t;
    while (i < n) {
        if (sset[i] > sset[k]) {
            k = i;
        }
        j = max(j, i);
        t = super(sset[i]);
        while (j < n && sset[j] <= t) {
            j++;
        }
        ans += (j - k - 1);
        cout << i << " " << k << " " << j << endl;
        i++;
    }
    long long total = n * 1LL * (n-1);
    cout << "Case #" << c << ": " << total - ans << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }            
}