#include <iostream>
using namespace std;

// find pos t[i] <= v, t[i+1] > v
int bin_life(int *t, int i, int l, int h, int v) {
    if (l <= h) {
        int m = (l+h)/2;
        int sub = 0;
        if (i > 0) sub = t[i-1];
        if (t[m]-sub <= v) {
            if (m < h) {
                if (t[m+1]-sub > v) return m;
                else return bin_life(t, i, m+1, h, v);
            }
            else if (m == h) return m;
        }
        else {
            return bin_life(t, i, l, m-1, v);
        }
    }
    else return h;
}

void print(int *array, int n) {
    for (int i = 0; i < n; i++) cout << array[i] << " ";
    cout << endl;
}

int main() {
    int n; cin >> n;
    int v[n], t[n], t1[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t1[i] = t[i];
        if (i > 0) t[i] += t[i-1];
    }
    // print(v, n);
    // print(t, n);
    int r[n], m[n];
    for (int i = 0; i < n; i++) {
        r[i] = 0;
        m[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int l = bin_life(t, i, i, n-1, v[i]);
        // cout << l << endl;

        if (l >= i) {
            r[i] += 1;
            if (l < n-1) {
                r[l+1] -= 1;
                m[l+1] += v[i] - t[l];
                if (i > 0) m[l+1] += t[i-1];
            }
        }
        else m[i] += v[i];
        // print(r, n);
        // print(m, n);
    }
    for (int i = 1; i < n; i++) r[i] += r[i-1];
    // print(r, n);
    for (int i = 0; i < n; i++) {
        cout << r[i]*t1[i] + m[i] << " ";
    }
    cout << endl;
}
