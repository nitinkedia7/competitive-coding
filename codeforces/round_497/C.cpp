#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array, array+n);
    int p = 0, np = 0, m = 0;
    while (p < n) {
        while (np < n && array[np] == array[p]) {
            np++;
        }
        cout << p << " " << np << endl;
        int d1 = np - p;
        int d2;
        if (np < n) d2 = n - np;
        else d2 = 0;
        cout << d1 << " " << d2 << endl;
        m += min(d1, d2);
        p = np;
    }
    cout << m << endl;
    return 0;
}