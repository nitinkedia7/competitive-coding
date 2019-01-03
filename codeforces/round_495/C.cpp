#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];
    int l[100001], r[100001];
    for (int i = 0; i < 100001; i++) {
        r[i] = 0;
        l[i] = 0;
    }
    l[array[0]]++;
    int d = 0;
    for (int i = 1; i < n; i++) {
        if (r[array[i]] == 0) d++;
        r[array[i]]++;
    }
    ll count = d;
    for (int i = 1; i < n-1; i++) {
        if (l[array[i]] == 0) {
            r[array[i]]--;
            if (r[array[i]] == 0) {
                d--;
            }
            count += d;
            // for (int j = 0; j < 100001; j++) {
            //     if (r[j]) {
            //         cout << array[i] << " " << j << endl;
            //     }
            // }
            l[array[i]]++;
        }
        else {
            r[array[i]]--;
            if (r[array[i]] == 0) {
                d--;
            }
            l[array[i]]++;
        }
    }
    cout << count << endl;
    return 0;
}