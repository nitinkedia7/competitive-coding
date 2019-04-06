#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void build(vector<int> &v, int N) {
    for (int i = N-2; i >= 0; i--) {
        v[i] = v[2*i+1] + v[2*i+2];
    }
}

void modify(vector<int> &v, int N, int i, int value) {
    i = N-1+i;
    v[i] = value;
    int p = i;
    while (p > 0) {
        p = (p-1)/2;
        v[p] = v[2*p+1] + v[2*p+2];
    }
}

int query(vector<int> &v, int N, int l, int r) { // [l, r)
    int res = 0;
    l += N-1;
    r += N-1;
    while (l < r) {
        if (l % 2 == 0) {
            res += v[l];
            l++;
        }
        l = l/2;
        if (r % 2 == 0) {
            res += v[--r];
        }
        r = r/2; 
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int N = 1;
    while (N < n) {
        N = N*2;
    }
    vector<int> v(2*N, 0); 
    for (int i = N-1; i < N-1+n; i++) {
        cin >> v[i];
    }
    cout << "input taken" << endl;
    build(v, N);
    cout << "build taken" << endl;
    // print(v);
    cout << query(v, N, 0, 2) << endl;
    modify(v, N, 0, 100);
    // print(v);
    cout << "modify taken" << endl;
    cout << query(v, N, 0, 2) << endl;
}