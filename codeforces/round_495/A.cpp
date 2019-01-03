#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    int c = 2;
    for (int i = 0; i < n-1; i++) {
        int diff = array[i+1] - array[i];
        if (diff > 2 * d) {
            c += 2;
        }
        else if (diff == 2*d) c += 1;
    }
    cout << c << "\n";
    return 0;
}